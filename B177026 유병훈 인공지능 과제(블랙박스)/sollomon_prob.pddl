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
        (have king child)
        (at king court)
        (at mom1 court)
        (at mom2 court)
        (at child court)
        (alive king)
        (alive mom1)
        (alive mom2)
        (alive child)
    )
    (:goal 
     (and
        (at mom2 prison)
        (have mom1 child)
        (not (alive mom2))
        (not (alive mom1))
        (alive king) 
        (not(alive child))
        (escape mom2 prison)
        (escape king court)
     )
    )
)

