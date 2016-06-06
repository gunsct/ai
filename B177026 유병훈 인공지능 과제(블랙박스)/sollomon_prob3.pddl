(define (problem strips-sollomon-1)
    (:domain strips-sollomon)
    (:objects
       king
       mom1
       mom2
       child
       
       court
       scaffold
       prison
       cartel
    )
    
    (:init
        (location court)
        (location scaffold)
        (location prison)
        (location cartel)
        (have mom1 child)
        (at king court)
        (at mom1 prison)
        (at mom2 prison)
        (at child scaffold)
        (alive king)
        (alive mom1)
        (alive mom2)
        (alive child)
    )
    (:goal 
     (and
        (at mom1 cartel)
        (at mom2 cartel)
        (kill mom1 mom2)
        (kill king mom1)
        (have king child)
        (not (alive mom2))
        (not (alive mom1))
        (alive king) 
        (kill king child)
        (not(alive child))
     )
    )
)

