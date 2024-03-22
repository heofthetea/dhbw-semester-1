% twice([X], [X, X]).
% twice([X|TX], [X, X | TY]) :- twice(TX, TY).

twice([], []).
twice([H|T], [H, H | TB]) :- twice(T, TB).

