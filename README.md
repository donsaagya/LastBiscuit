# LastBiscuit
This is a project that models the game of last biscuit in C++(similar to the game of nim).
In this game, there are 2 barrels of biscuits(barrel A starting with 6 and barrel B starting with 8) and 2 players,

The game is played in turns,
where each player is allowed to take as many biscuits as they want either from one of the barrels of their choosing or from both of them.

If a player chooses to pick biscuits from both barrels, the maximum biscuits they can pick is the biscuits that are remaining
in the barrel with the lesser biscuits.
e.g) if barrel A has 8 biscuits and barrel B has 6, the maximum biscuits that the user can take would be up to 6 from both of them at once, since anything greater than 6 the barrel B can't make up for.

Each player is also allowed to skip their turn, although this can only be done once.
The player who picks the last biscuit is the winner.
