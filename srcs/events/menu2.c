#include "../../includes/3d_engine.h"

/*void    makebutton(t_env *e, char *quote, SDL_Color textColor)
{
    SDL_Surface *text;
    SDL_Surface textPos;

    if(SDL_BlitSurface(env->menu.button, NULL, env->winsurf, &env->menu.button1Pos) == -1)
        printf("error blitsurface");
    //Ecrire sur le button
    if(!(text = TTF_RenderText_Solid(env->menu.font, quote, textColor)))
           printf("%s\n", TTF_GetError());
    textPos.x = button1Pos.x + env->menu.button->w * 0.4;
    textPos.y = button1Pos.y + env->menu.button->h * 0.4;
    SDL_BlitSurface(text, NULL, env->winsurf, textPos);
}*/

/*void    WriteOnScreen(t_env *e, char* quote, SDL_Color textColor)
{
    SDL_Surface *text;
    SDL_Rect    textPos;

    if(!(text = TTF_RenderText_Solid(env->menu.font, quote, textColor)))
           printf("%s\n", TTF_GetError());
    textPos.x = (env->winsurf->w / 2) - (text->w / 2);
    textPos.y = (env->winsurf->h - text->h);
    SDL_BlitSurface(text, NULL, env->winsurf, textPos);
    SDL_FreeSurface(text);
    free(textPos);
}*/

void    main_menu(t_env *env)
{
    env->menu.textColor = (SDL_Color){0, 0, 0, 0};
    env->menu.bgColor = (SDL_Color){0, 0, 0};

    SDL_FillRect(env->winsurf, NULL, 0x00000000);
    if(SDL_BlitSurface(env->menu.menu1, NULL, env->winsurf, NULL) == -1)
        printf("error blitsurface");
    //Ecrire le RAGEQUIT
    if(!(env->menu.text = TTF_RenderText_Solid(env->menu.font, "ESC to RAGEQUIT", env->menu.textColor)))
           printf("%s\n", TTF_GetError());
    env->menu.textPos.x = (env->winsurf->w / 2) - (env->menu.text->w / 2);
    env->menu.textPos.y = (env->winsurf->h - env->menu.text->h);
    SDL_BlitSurface(env->menu.text, NULL, env->winsurf, &env->menu.textPos);
    //charge le button
    /*env->menu.button = IMG_Load("includes/assets/tiles/buttonMenu.png");
    if(!env->menu.button) 
        printf("IMG_Load: %s\n", IMG_GetError());*/
    //affiche le button1
    env->menu.button1Pos.y = env->menu.button2Pos.y = (env->winsurf->h - env->menu.button->h) * 0.99;
    env->menu.button1Pos.x = (env->winsurf->w / 2) - (env->menu.button->w) - BUTTON_MARGE;
    if(SDL_BlitSurface(env->menu.button, NULL, env->winsurf, &env->menu.button1Pos) == -1)
        printf("error blitsurface");
    //Ecrire sur le button
    if(!(env->menu.text = TTF_RenderText_Solid(env->menu.font, "PLAY", (SDL_Color){255, 255, 255})))
            printf("%s\n", TTF_GetError());
    env->menu.textPos.x = env->menu.button1Pos.x + env->menu.button->w * 0.4;
    env->menu.textPos.y = env->menu.button1Pos.y + env->menu.button->h * 0.4;
    SDL_BlitSurface(env->menu.text, NULL, env->winsurf, &env->menu.textPos);
    //affiche le button2
    env->menu.button2Pos.x = (env->winsurf->w / 2) + BUTTON_MARGE;
    SDL_BlitSurface(env->menu.button, NULL, env->winsurf, &env->menu.button2Pos);
    //Ecrire sur le button
    if(!(env->menu.text = TTF_RenderText_Solid(env->menu.font, "FORGE", (SDL_Color){255, 255, 255})))
        printf("%s\n", TTF_GetError());
    env->menu.textPos.x = env->menu.button2Pos.x + env->menu.button->w * 0.4;
    env->menu.textPos.y = env->menu.button2Pos.y + env->menu.button->h * 0.4;
    SDL_BlitSurface(env->menu.text, NULL, env->winsurf, &env->menu.textPos);
    //TTF_CloseFont(env->menu.font);
}

void       pause_menu(t_env *env)
{
    SDL_FillRect(env->winsurf, NULL, 0x00000000);
    if(SDL_BlitSurface(env->menu.menu2, NULL, env->winsurf, NULL) == -1)
        printf("error blitsurface");
    env->menu.button = IMG_Load("includes/assets/tiles/buttonMenu.png");

    env->menu.button1Pos.x = env->menu.button2Pos.x = (env->winsurf->w / 2 - env->menu.button->w) / 2;
    env->menu.button1Pos.y = (env->winsurf->h - BUTTON_MARGE) / 2 - env->menu.button->h;
    SDL_BlitSurface(env->menu.button, NULL, env->winsurf, &env->menu.button1Pos);
    
    if(!(env->menu.text = TTF_RenderText_Solid(env->menu.font, "RESUME", (SDL_Color){255, 255, 255})))
    {
        printf("%s\n", TTF_GetError());
    }
    env->menu.textPos.x = env->menu.button1Pos.x + env->menu.button->w * 0.4;
    env->menu.textPos.y = env->menu.button1Pos.y + env->menu.button->h * 0.4;
    SDL_BlitSurface(env->menu.text, NULL, env->winsurf, &env->menu.textPos);
    //env->menu.button = IMG_Load("includes/assets/tiles/buttonMenu.png");
            
    env->menu.button2Pos.y = (env->winsurf->h + BUTTON_MARGE) / 2;
    SDL_BlitSurface(env->menu.button, NULL, env->winsurf, &env->menu.button2Pos);  

    if(!(env->menu.text = TTF_RenderText_Solid(env->menu.font, "OPTION", (SDL_Color){255, 255, 255})))
    {
        printf("%s\n", TTF_GetError());
    }
    env->menu.textPos.x = env->menu.button2Pos.x + env->menu.button->w * 0.4;
    env->menu.textPos.y = env->menu.button2Pos.y + env->menu.button->h * 0.4;
    SDL_BlitSurface(env->menu.text, NULL, env->winsurf, &env->menu.textPos);       
}

void    event_MainMenu(t_env *env)
{
    while(SDL_PollEvent(&env->event))
    {
        if ((env->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE
		    && env->event.type == SDL_KEYDOWN)
                || env->event.type == SDL_QUIT)
            ft_exit(env, "fini\n", 1);
        if(env->key[LCLICK] == 1 && env->event.button.button == SDL_BUTTON_LEFT)
                    {
                        SDL_GetMouseState(&env->clicks.x, &env->clicks.y);
                        printf("%d, %d\n", env->clicks.x, env->clicks.y);
                        if(env->clicks.y > env->menu.button1Pos.y
                          && env->clicks.y <= env->menu.button1Pos.y + env->menu.button->h
                          && env->clicks.x > env->menu.button1Pos.x
                          && env->clicks.x <= env->menu.button1Pos.x + env->menu.button->w)
                          {
                              if(env->usr.platform == MENU)
                              {
                                  printf("GAME\n");
                                  env->usr.platform = GAME;
                              }
                              else if(env->usr.platform == PAUSE)
                              {
                                  printf("GAME\n");
                                  env->usr.platform = GAME;
                              }
                          }
                        else if(env->clicks.y > env->menu.button2Pos.y
                          && env->clicks.y <= env->menu.button2Pos.y + env->menu.button->h
                          && env->clicks.x > env->menu.button2Pos.x
                          && env->clicks.x <= env->menu.button2Pos.x + env->menu.button->w)
                          {
                              if(env->usr.platform == MENU)
                              {
                                  printf("FORGE\n");
                                  //env->usr.platform = FORGE;
                              }
                              else if(env->usr.platform == PAUSE)
                              {
                                  printf("OPTION\n");
                                  //env->usr.platform = OPTION;
                              }
                          }
                        break;
                    }
        key_tab(env);
    }
    //SDL_FreeSurface(env->menu.button);
    SDL_FreeSurface(env->menu.text);
}