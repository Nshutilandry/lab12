#ifndef ARCADE_GAME_H
#define ARCADE_GAME_H

#include <string>

/// @file game.h
/// @brief Shared interface and score state for arcade games.
class Game {
public:
  explicit Game(std::string title);
  ~Game();

  const std::string &title() const;
  int last_score() const;
  void play();

protected:
  void set_score(int score);
  bool ask_play_again() const;

private:
  std::string m_title;
  int m_last_score;
};

#endif // ARCADE_GAME_H
