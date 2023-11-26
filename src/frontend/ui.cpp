// // #include "globals.hpp"
// // #include "EqtMiniMap.hpp"
// // #include "EqtStatusUI.hpp"
// #include "frontend/frontend.hpp"

// lv_obj_t screen;
// lv_obj_tname_label = NULL;
// lv_obj_t status_label;
// lv_obj_tdesc_label;
// lv_obj_t notif_popup;
// EqtMiniMapmini_map;

// void displaymain_setup()
// {
//     screen = lv_obj_create(NULL);
//     lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);
//     static lv_style_t name_style;
//     lv_style_init(&name_style);

//     name_label = lv_label_create(screen);
//     lv_label_set_text(name_label, "No Machine select");
//     lv_obj_add_style(name_label, &name_style, 0);
//     lv_style_set_text_font(&name_style, &lv_font_montserrat_20);
//     lv_style_set_text_color(&name_style, lv_color_black());
//     lv_obj_align(name_label, LV_ALIGN_CENTER, 0, -80);

//     static lv_style_t status_style;
//     lv_style_init(&status_style);

//     status_label = lv_label_create(screen);
//     lv_label_set_text(status_label, "No Status to report");
//     lv_obj_add_style(status_label, &status_style, 0);
//     lv_style_set_text_font(&status_style, &lv_font_montserrat_16);
//     lv_style_set_text_color(&status_style, lv_color_black());
//     lv_obj_align(status_label, LV_ALIGN_CENTER, 0, -60);

//     desc_label = lv_label_create(screen);
//     lv_label_set_text(desc_label, "Put description here");
//     lv_obj_add_style(desc_label, &status_style, 0);
//     lv_obj_align(desc_label, LV_ALIGN_CENTER, 0, -15);

//     notif_popup = lv_obj_create(screen);
//     lv_obj_set_style_bg_color(notif_popup, lv_palette_main(LV_PALETTE_RED), 0);

//     static lv_style_t exclamation_style;
//     lv_style_init(&exclamation_style);

//     lv_obj_t *exclamation = lv_label_create(notif_popup);
//     lv_obj_add_style(exclamation, &exclamation_style, 0);
//     lv_label_set_text(exclamation, "!");
//     lv_style_set_text_color(&exclamation_style, lv_color_white());
//     lv_obj_set_align(exclamation, LV_ALIGN_CENTER);

//    // Setup transform
//     lv_obj_set_size(notif_popup, 20, 20);
//     lv_obj_set_x(notif_popup, 210);
//     lv_obj_set_y(notif_popup, 65);
// }

// void init_mini_man()
// {
//     mini_map = new EqtMiniMap(screen, eqt_count);
// }

// void displaymain_display()
// {
//     // Serial.printf("eqts: id: %d, count: %d, size: %d\n", eqt_index, eqt_count, eqt_list.size());
//     // Serial.printf("description: %s\n", eqt_list[eqt_index].description.c_str());
//     // char lol = (char)calloc(1000, 1);
//     // memcpy(lol, eqt_list[eqt_index].description.c_str(), strlen(eqt_list[eqt_index].description.c_str()));
//     // Serial.printf("ewdwdd, %s\n", lol);
//     if (name_label)
//     {
//         lv_label_set_text(name_label, eqt_list[eqt_index].description.c_str());
//         //free(lol);
//         if (notif_map.size() > 0) {
//             Serial.printf(WARN "cursed: %d\n", notif_map[eqt_list[eqt_index].id].size());
//             if (notif_map[eqt_list[eqt_index].id].size() > 0) {
//                 lv_label_set_text(status_label, notif_map[eqt_list[eqt_index].id][0].title.c_str());
//                 Serial.printf("id: %d, title: %s\n", eqt_index, notif_map[eqt_list[eqt_index].id][0].title.c_str());
//             } else {
//                 lv_label_set_text(status_label, "--");
//                 Serial.printf("title: --\n");
//             }
//         }
//     }
//     mini_map->setCurrent(eqt_index);
//     if (lv_scr_act() != screen)
//         lv_scr_load(screen);
// }

// ´´´
