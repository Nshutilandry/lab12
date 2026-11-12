# Arcade class diagram

```mermaid
classDiagram
  Game <|-- Hangman
  Game <|-- Dungeon
  Game <|-- Blackjack
  Game <|-- Minesweeper

  class Game {
    -string m_title
    -int m_last_score
    +play()
    +title()
    +last_score()
    #set_score()
    #ask_play_again()
  }
  class Hangman {
    -int m_times_played
    +play()
    +times_played()
  }
  class Dungeon {
    -int m_times_played
    +play()
    +times_played()
  }
  class Blackjack {
    -int m_times_played
    +play()
    +times_played()
  }
  class Minesweeper {
    -int m_times_played
    +play()
    +times_played()
  }

  Hangman --> play_hangman : wraps
  Dungeon --> play_dungeon : wraps
  Blackjack --> play_blackjack : wraps
  Minesweeper --> play_minesweeper : wraps
```

The upward arrows mean public inheritance (“is a”). The plain arrows show
which free-function implementation each wrapper uses.
There are no composition diamonds: the derived classes do not own a game
engine, deck, board, or player.
