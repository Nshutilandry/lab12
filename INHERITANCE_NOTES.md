# Inheritance notes

## 1. Overriding or hiding?

`Game *g = &hangman; g->play();` prints `Game::play called.` because `play()`
is not virtual. `Hangman::play()` hides the base function; it does not override
it. A call through `Game *` runs `Game::play()`, while a call through a
`Hangman` object runs `Hangman::play()`.

## 2. Slicing

`Game copy = hangman;` copies only the `Game` subobject: its title and most
recent score. The `Hangman`-specific `m_times_played` member and derived
behavior are not part of `copy`. This loss of the derived portion is object
slicing.

## 3. protected

`protected` lets `Game`'s derived classes use a member while keeping it
inaccessible to unrelated callers. `set_score` is protected so a derived
game can record the score returned by its wrapped function, but callers cannot
arbitrarily change a game's score.

## 4. Procedural versus object-oriented Hangman

- **Where the data lives:** The wrapper object keeps its title, last score, and
  play count. The word, masked word, guesses, and misses are still local to
  the procedural `play_hangman()` function.
- **Who can change it:** `Game` changes the title and score; `Hangman` changes
  its play count. The free function manages its own round state.
- **How I would add a second Hangman variant:** I would add a new wrapper or
  parameterize/extract the shared game logic. Inheriting from `Hangman` alone
  would not make `play()` dispatch polymorphically because it is non-virtual.
- **How I would test it:** I would test score/helper functions independently
  and exercise each wrapper through controlled input, checking its score and
  play count afterward.

The derived classes need no custom copy constructor or destructor: their only
additional state is an `int`, and the `Game` base owns an ordinary `std::string`
and an `int`. The compiler-generated operations correctly copy and destroy
those members.
