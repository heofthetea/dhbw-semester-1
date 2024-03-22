
filter([], []).


filter([H | T], Not_numbers) :-
    number(H), 
    !, 
    filter(T, Not_numbers).


filter([H | T], [H | A]) :-
    filter(T, A).


