abs(X,Y) :- X >= 0, !, X = Y.
abs(X, Y) :- Y is -X.