#include "frontend.hpp"

void lv_example_get_started_1(void)
{
    // Change la couleur de fond de l'écran actif
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x003a57), LV_PART_MAIN);

    //Crée un label blanc, définit son texte et l'aligne au centre
    lv_obj_t * label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello world");
    lv_obj_set_style_text_color(lv_scr_act(), lv_color_hex(0xffffff), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}
