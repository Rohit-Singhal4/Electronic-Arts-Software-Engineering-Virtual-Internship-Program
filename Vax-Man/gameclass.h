#ifndef GAMECLASS_H
#define GAMECLASS_H

#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <QTimer>
#include <QTimerEvent> 
#include <QObject>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "pacman.h"
#include "ghost.h"
#include "blinky.h"
#include "pinky.h"
#include "clyde.h"
#include "inky.h"

class   GameLoop : public QGraphicsView
{	
  Q_OBJECT
private:
    QGraphicsScene                          *scene = nullptr;
    QGraphicsView                           *view = nullptr;
    QGraphicsPixmapItem                     **map_pix = nullptr;
    PacMan                                  *pacman = nullptr;

    int                                     **map_int;
    QTimer                                  *timer_pacman = nullptr;
    bool                                    gameIsLost = false;

    QTimer                                  *timer_double_ghosts = nullptr;

    Clyde                                   *clydes[128];
    Inky                                    *inkys[128];
    Pinky                                   *pinkys[128];
    Blinky                                  *blinkys[128];            

    QTimer                                  *timer_blinkys[128];
    QTimer                                  *timer_pinkys[128];
    QTimer                                  *timer_inkys[128];
    QTimer                                  *timer_clydes[128];

public:
                                            GameLoop(char *file_name);
                                            ~GameLoop();
    void                                    ft_write_line_map(int *map, std::string str);
    void                                    ft_roll_game();
    void                                    ft_create_map();
    int                                     ft_check_file_inp(std::string str);	

    void ft_set_is_game_lost(bool isLost);
public slots:
    void                                    ghostDoubling(); 
    void                                    ghostDied();
};

#endif // GAMECLASS_H
