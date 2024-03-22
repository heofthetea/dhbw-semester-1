% m([], [], []).
% m([HA | TA], [HB | TB], TC) :- 
%     HA =:= HB,
%     m(TA, TB, TC).
% m([HA | TA], [HB | TB], [[HA, HB] | TC]) :-
%     HA =\= HB,
%     m(TA, TB, TC).


m([],[],[]). 
m([HA|TA],[HB|TB],TC) :- HA =:= HB, m(TA,TB,TC). 
m([HA|TA],[HB|TB],[[HA,HB]|TC]) :- HA =\= HB, m(TA,TB,TC).