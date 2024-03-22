combine_tuple([], [], []).
combine_tuple([HA | TA], [HB | TB], [[HA, HB] | TC]) :-
    combine_tuple(TA, TB, TC).