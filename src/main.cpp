#include "main.hpp"


lv_obj_t* accepte;
TWatchClass *twatch = nullptr;
TFT_eSPI *tft = nullptr;

lv_obj_t* header; // Ajout du header
lv_obj_t* notification_container; // Ajout du conteneur des notifications


int currentNotification = 0; // Indice de la notification actuelle
int btn3Pressed = 0;
int btn2Pressed = 0;
int btn1Pressed = 0;

static void textarea_event_handler(lv_event_t * e)
{
    lv_obj_t * ta = lv_event_get_target(e);
    LV_LOG_USER("Enter was pressed. The current text is: %s", lv_textarea_get_text(ta));
}

//test
void create_notification(const char* text, int y_offset) {
    lv_obj_t* notification = lv_textarea_create(notification_container);
    lv_textarea_set_text(notification, text);
	lv_obj_set_width(notification, 190);
    lv_obj_align(notification, LV_ALIGN_TOP_MID, 0, y_offset);
    lv_obj_add_event_cb(notification, textarea_event_handler, LV_EVENT_READY, notification);
}

void lv_example_textarea_1(void)
{
    notification_container = lv_obj_create(lv_scr_act());
    lv_obj_set_size(notification_container, LV_HOR_RES, LV_VER_RES - 50); // Hauteur de l'écran moins la taille du header
    lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50);

    // Création du header
    header = lv_obj_create(lv_scr_act());
    lv_obj_set_size(header, LV_HOR_RES, 50); // Hauteur du header
    lv_obj_align(header, LV_ALIGN_TOP_MID, 0, 0);
    
    // Ajout d'un label pour l'ID dans le header
    lv_obj_t* id_label = lv_label_create(header);
    lv_label_set_text(id_label, "Votre ID"); // Remplacez par votre ID
    lv_obj_align(id_label, LV_ALIGN_TOP_MID, 0, 10);

	// recup backend notif
	std::vector<Notification> notifs;
	string url = "http://mes.42lausanne.ch/api/v1/Notification/";
	for (int i = 1167; i < 1177; i++)
	{
		Notification temp;
		string stemp = url + std::to_string(i);
		getRequestNotification(stemp.c_str(), temp);
		notifs.push_back(temp);
	}

	int y = 10;
	for (std::vector<Notification>::iterator it = notifs.begin(); it != notifs.end(); ++it)
	{
		create_notification(it->getTitle().c_str(), y);
		y += 50;
	}
	    // Création de 5 notifications initiales
    // create_notification("Notification 1", 10);
    // create_notification("Notification 2", 60);
    // create_notification("Notification 3", 110);
    // create_notification("Notification 4", 160);
    // create_notification("Notification 5", 210);

}

void btn1_click(void *param) {
  btn1Pressed = 1;  
  Serial.println("BTN1 Click");
  tft->drawString("BTN1 Click", 80, 118);
  twatch->motor_shake(2, 50);
}

void btn2_click(void *param) {
  btn2Pressed = 1;
  Serial.println("BTN2 Click");
  tft->drawString("BTN2 Click", 80, 118);
  twatch->motor_shake(2, 50);
    // Défilement vers le haut
  if (currentNotification > 0) {
    currentNotification--;
    lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50 + (currentNotification * 50));
  }
}

void btn3_click(void *param) {
  Serial.println("BTN3 Click");
  Serial.println(btn3Pressed);
  tft->drawString("BTN3 Click", 80, 118);
  twatch->motor_shake(2, 50);
//   lv_scr_load(accepte);
    // Défilement vers le bas
  if (currentNotification < 4) {
    currentNotification++;
    lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50 + (currentNotification * 50));
  }
}

char buf[128];

void front_ui() {
  
  lv_example_get_started_1();
  lv_example_textarea_1();
  accepte = lv_obj_create(NULL); /*Create a parent object on the current screen*/
  Serial.println(btn3Pressed);
  lv_obj_set_size(accepte, 80, 50);
  lv_obj_align(accepte, LV_ALIGN_CENTER, 0, 0);
}

void set_font(TWatchClass **twatch, TFT_eSPI **tft) {
  (*tft)->setTextFont(2);
  (*tft)->setTextColor(TFT_WHITE, TFT_BLACK);
  (*tft)->drawString("T-Watch Touch Test", 62, 90);
  (*twatch)->motor_shake(2, 50);
  (*tft)->fillScreen(TFT_BLACK);
  (*twatch)->backlight_set_value(255);
  (*twatch)->hal_auto_update(true, 0);
}

void buttonClick(TWatchClass **twatch, TFT_eSPI **tft) {
  (*tft)->setTextFont(2);
  (*tft)->setTextColor(TFT_BLACK, TFT_WHITE);
  (*tft)->drawString("T-Watch Button Test", 62, 90);

  (*twatch)->button_bind_event(TWATCH_BTN_1, BUTTON_CLICK, btn1_click);
  (*twatch)->button_bind_event(TWATCH_BTN_2, BUTTON_CLICK, btn2_click);
  (*twatch)->button_bind_event(TWATCH_BTN_3, BUTTON_CLICK, btn3_click);
}

void setup() {
  // analogValue = analogRead(0);
  twatch = TWatchClass::getWatch();
  tft = twatch->tft_get_instance();

  Serial.begin(115200);
  twatch->motor_shake(2, 50);

  tft->fillScreen(TFT_BLACK);
  twatch->backlight_set_value(255);

  set_font(&twatch, &tft);
  buttonClick(&twatch, &tft);
  backend(tft, twatch);
  front_ui();
}

void loop() {
  delay(20);
}
