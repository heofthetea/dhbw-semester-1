
palindrome([]).
palindrome([_]).
%palindrome([H|[]]) :- length([H], 1).

palindrome([H|T]) :-
    append(A, [H], T),
    palindrome(A),
    !. % cut makes sure that output `true ; false` doesn't appear.


% palindrome([a, b, b, a]).
% palindrome([a, b, c, b, a]).
% NOT palindrome([a, b, c]).