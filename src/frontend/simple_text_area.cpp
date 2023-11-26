#include "frontend.hpp"

//test
// lv_obj_t* header; // Ajout du header
// lv_obj_t* notification_container; // Ajout du conteneur des notifications

// static void textarea_event_handler(lv_event_t * e)
// {
//     lv_obj_t * ta = lv_event_get_target(e);
//     LV_LOG_USER("Enter was pressed. The current text is: %s", lv_textarea_get_text(ta));
// }

static void btnm_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * ta = (lv_obj_t *)lv_event_get_user_data(e);
    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));

    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) lv_textarea_del_char(ta);
    else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0) lv_event_send(ta, LV_EVENT_READY, NULL);
    else lv_textarea_add_text(ta, txt);

}

//test
// void create_notification(const char* text, int y_offset) {
//     lv_obj_t* notification = lv_textarea_create(notification_container);
//     lv_textarea_set_text(notification, text);
//     lv_obj_align(notification, LV_ALIGN_TOP_MID, 0, y_offset);
//     lv_obj_add_event_cb(notification, textarea_event_handler, LV_EVENT_READY, notification);
// }

// void lv_example_textarea_1(void)
// {
//     lv_obj_t * ta = lv_textarea_create(lv_scr_act());
//     lv_textarea_set_one_line(ta, true);
//     lv_obj_align(ta, LV_ALIGN_TOP_MID, 0, 10);
//     lv_obj_add_event_cb(ta, textarea_event_handler, LV_EVENT_READY, ta);
//     // lv_obj_add_state(ta, LV_STATE_FOCUSED); /*To be sure the cursor is visible*/

//     // static const char * btnm_map[] = {"1", "2", "3", "\n",
//     //                                   "4", "5", "6", "\n",
//     //                                   "7", "8", "9", "\n",
//     //                                   LV_SYMBOL_BACKSPACE, "0", LV_SYMBOL_NEW_LINE, ""
//     //                                  };

//     // lv_obj_t * btnm = lv_btnmatrix_create(lv_scr_act());
//     // lv_obj_set_size(btnm, 200, 150);
//     // lv_obj_align(btnm, LV_ALIGN_BOTTOM_MID, 0, -10);
//     // lv_obj_add_event_cb(btnm, btnm_event_handler, LV_EVENT_VALUE_CHANGED, ta);
//     // lv_obj_clear_flag(btnm, LV_OBJ_FLAG_CLICK_FOCUSABLE); /*To keep the text area focused on button clicks*/
//     // lv_btnmatrix_set_map(btnm, btnm_map);
// }
// void lv_example_textarea_1(void)
// {
//     notification_container = lv_obj_create(lv_scr_act());
//     lv_obj_set_size(notification_container, LV_HOR_RES, LV_VER_RES - 50); // Hauteur de l'écran moins la taille du header
//     lv_obj_align(notification_container, LV_ALIGN_TOP_MID, 0, 50);

//     // Création du header
//     header = lv_obj_create(lv_scr_act());
//     lv_obj_set_size(header, LV_HOR_RES, 50); // Hauteur du header
//     lv_obj_align(header, LV_ALIGN_TOP_MID, 0, 0);
    
//     // Ajout d'un label pour l'ID dans le header
//     lv_obj_t* id_label = lv_label_create(header);
//     lv_label_set_text(id_label, "Votre ID"); // Remplacez par votre ID
//     lv_obj_align(id_label, LV_ALIGN_TOP_MID, 0, 10);

// 	    // Création de 5 notifications initiales
//     create_notification("Notification 1", 10);
//     create_notification("Notification 2", 60);
//     create_notification("Notification 3", 110);
//     create_notification("Notification 4", 160);
//     create_notification("Notification 5", 210);
// }