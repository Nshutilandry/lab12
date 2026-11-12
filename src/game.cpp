#include "game.h"

#include <iostream>
#include <string>

#include "input.h"

Game::Game(std::string title) : m_title{title}, m_last_score{0} {}

Game::~Game() = default;

const std::string &Game::title() const { return m_title; }

int Game::last_score() const { return m_last_score; }

void Game::play() { std::cout << "Game::play called.\n"; }

void Game::set_score(int score) { m_last_score = score; }

bool Game::ask_play_again() const {
  std::string answer;
  while (prompt_line("Play again? (y/n): ", answer)) {
    if (answer == "y" || answer == "Y") {
      return true;
    }
    if (answer == "n" || answer == "N") {
      return false;
    }
    std::cout << "Please enter y or n.\n";
  }
  return false;
}
