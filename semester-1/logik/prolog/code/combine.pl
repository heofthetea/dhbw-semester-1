
combine_list([], [], []).

combine_list([HA | TA], [HB | TB], [HA, HB | TC]) :-
    combine_list(TA, TB, TC).