% a([], 0).
% a([H|T], B) :- H >= 0, a(T, C), B is C + H.
% a([H|T], B) :- H < 0, a(T, C), B is C - H.


a(List, Sum) :- a(List, 0, Sum).

% Predicate to calculate the sum of positive and negative numbers in a list
% a/2 takes a list and returns the sum of its elements
a(List, Sum) :- a(List, 0, Sum).

% Base case: when the list is empty, return the accumulated sum
a([], Acc, Acc).

% Recursive case:
% If the head of the list (H) is non-negative,
% add it to the accumulator (Acc) and recursively process the tail (T)
a([H|T], Acc, Sum) :-
    H >= 0, 
    !,                 % Check if H is non-negative
    NewAcc is Acc + H,      % Add H to the accumulator, store the result in NewAcc
    a(T, NewAcc, Sum).      % Recursive call with the updated accumulator

% Recursive case:
% If the head of the list (H) is negative,
% subtract its absolute value from the accumulator (Acc) and recursively process the tail (T)
a([H|T], Acc, Sum) :-
    H < 0,                  % Check if H is negative
    NewAcc is Acc - H,      % Subtract the absolute value of H from the accumulator, store the result in NewAcc
    a(T, NewAcc, Sum).      % Recursive call with the updated accumulator
