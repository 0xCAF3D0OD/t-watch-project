#include "frontend.hpp"

static void btnm_event_handler(lv_event_t * e)
{
    // Récupère l'objet (bouton de la matrice de boutons) qui a déclenché l'événement
    lv_obj_t * obj = lv_event_get_target(e);
    // Récupère l'objet associé à l'événement (dans ce cas, un objet de zone de texte)
    lv_obj_t * ta = (lv_obj_t *)lv_event_get_user_data(e);
    // Récupère le texte du bouton de la matrice de boutons sélectionné
    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    // Vérifie le texte du bouton pour déterminer l'action à effectuer
    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0)
    {
        // Si le texte correspond au symbole de suppression ("BACKSPACE"), supprime un caractère de la zone de texte
        lv_textarea_del_char(ta);
    }
    else if(strcmp(txt, LV_SYMBOL_NEW_LINE) == 0)
    {
        // Si le texte correspond au symbole de nouvelle ligne, envoie un événement "READY" à la zone de texte
        lv_event_send(ta, LV_EVENT_READY, NULL);
    }
    else
    {
        // Sinon, ajoute le texte du bouton à la zone de texte
        lv_textarea_add_text(ta, txt);
    }
}
