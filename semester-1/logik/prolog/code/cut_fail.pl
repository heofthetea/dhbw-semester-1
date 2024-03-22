
likes(vincent, X) :- 
    burger(X),
    % X \== kahuna.
    not(X = kahuna).

burger(bigMac).
burger(kahuna).
burger(royale).
