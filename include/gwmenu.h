#ifndef H__GWMENU__H
#define H__GWMENU__H

#include <memory>
#include <vector>
#include "platform.h"
#include "gamelist.h"

class GW_Menu
{
public:
    GW_Menu(GW_Platform *platform, GW_GameList *gamelist) :
        platform_(platform), gamelist_(gamelist), changed_(true),
        current_(-1), bg_(NULL) {}

    void Run();
protected:
    void draw_text_center(int y, const string &text);
    void draw_textbox_center(int y, const string &text, GW_Platform_RGB &color, GW_Platform_Rect *touch_rect, bool box);
private:
    bool process_event(GW_Platform_Event *event);
    void draw_title();
    void draw_title_and_line(int y, int spacing, const string &title);
    void draw_gamelist();
    void draw_bg();
    void rungame();

    void current_set(int cur);

    GW_Platform *platform_;
    GW_GameList *gamelist_;
    bool changed_;
    int current_;
    std::auto_ptr<GW_Platform_Image> bg_;
    vector<GW_Platform_Rect*> touch_map_;
};


#endif //H__GWMENU__H