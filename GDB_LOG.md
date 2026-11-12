# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12) — 2026-11-12

**Debugger session status:** GDB is not available in this editor workspace, so
no debugger output is claimed as observed. Run the commands below in the local
Debug build and replace the prompts with the actual output and observations.

### The constructor chain

Commands to run, in order (record output and explain it):

```text
gdb ./build/arcade
(gdb) break Hangman::Hangman
(gdb) run
(gdb) bt
(gdb) step
(gdb) bt
(gdb) finish
(gdb) break Hangman::~Hangman
(gdb) break Game::~Game
(gdb) continue
```

When the arcade menu appears, enter `0` so execution reaches the destructors.
`Game::~Game` will be reached once for each game object; use `continue` after
each stop and note which derived destructor was active.

Backtrace inside `Hangman::Hangman` (paste actual output):

Backtrace inside `Game::Game` (paste actual output):

Where `finish` returned to (paste actual output):

Order of destructor breakpoints when the program ended (paste actual output):

Construction order and destruction order, as read from the backtraces:

### What a base pointer shows

Temporarily add `Game *g = &hangman;` in `main`, then stop after that
initialization:

```text
(gdb) set print pretty on
(gdb) print hangman
(gdb) print *g
(gdb) ptype Hangman
(gdb) ptype g
(gdb) whatis g
```

`print hangman` (paste actual output):

`print *g` (paste actual output):

What is different, and why:

`ptype Hangman` and `ptype g` (paste actual output):

One sentence on what `ptype Hangman` revealed about inheritance:

The base-class data visible in `Hangman` should include `m_title` and
`m_last_score`; `whatis g` should identify the expression as `Game *`.
