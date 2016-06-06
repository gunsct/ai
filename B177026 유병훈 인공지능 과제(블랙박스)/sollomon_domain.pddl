;;sollomon domain file
(define (domain strips-sollomon)
  (:requirements :strips) 
  (:predicates 	
	       	  (at ?x ?loc); x is at loc
              (have ?x ?sth); x has sth
              (location ?loc); loc is a location
              (kill ?x ?y); x kill y
              (escape ?x ?loc); x escape
              (fight ?x ?y); x vs y
              (win ?x ?y); x win for y
              (alive ?x); x alive
  )
; x moves from loc1 to loc2
(:action move-to-prison
  :parameters
    (?x ?y ?loc1 ?loc2); y가 loc1에서 loc2로 이동
  :precondition
    (and (location ?loc1) (location ?loc2) (at ?x ?loc1) (at ?y ?loc1) (win ?x ?y) )
  :effect
    (and  (not (at ?y ?loc1)) (at ?y ?loc2) )
)

; y escape from loc
(:action escape-to-prison
  :parameters
    (?x ?loc); y가 loc에서 탈주
  :precondition
    (and (location ?loc) (at ?x ?loc) )
  :effect
    (and  (escape ?x ?loc) )
)

; y escape from loc
(:action escape-to-prison
  :parameters
    (?x ?y ?loc); y가 loc에서 탈주
  :precondition
    (and (location ?loc) (at ?x ?loc) (win ?x ?y) )
  :effect
    (and  (escape ?y ?loc) )
)

; x moves from loc1 to loc2
(:action move-to-scaffold
  :parameters
    (?x ?y ?loc1 ?loc2); y가 loc1에서 loc2로 이동
  :precondition
    (and (location ?loc1) (location ?loc2) (at ?x ?loc1) (at ?y ?loc1) (win ?x ?y))
  :effect
    (and  (not (at ?y ?loc1)) (at ?y ?loc2) )
)

; x moves from loc1 to loc2
(:action move-to-cartel
  :parameters
    (?x ?y ?loc1 ?loc2); x가 loc1에서 loc2로 이동
  :precondition
    (and (location ?loc1) (location ?loc2) (at ?x ?loc1) (at ?y ?loc1) )
  :effect
    (and  (not (at ?x ?loc1)) (at ?x ?loc2) (not (at ?y ?loc1)) (at ?y ?loc2) (fight ?x ?y) )
)
    
; delivers sth to y at loc
(:action delivers
  :parameters
    (?x ?sth ?y ?z ?loc); x가 sth을 y에게 loc에서 전달
  :precondition
    (and (at ?x ?loc) (at ?y ?loc) (have ?x ?sth) (alive ?x) (win ?y ?z) )
  :effect
    (and  (not(have ?x ?sth)) (have ?y ?sth) )
 )
 
; x win for y at loc
(:action wins
  :parameters
   (?x ?y ?loc); x가 y를 loc에서 이김
  :precondition
   (and (at ?x ?loc) (at ?y ?loc) (alive ?x) (alive ?y) )
  :effect
   (and (win ?x ?y) )
 )
 
 ; x win for y at loc
(:action wins-fight
  :parameters
   (?x ?y ?loc); x가 y를 loc에서 이겨 죽임
  :precondition
   (and (at ?x ?loc) (at ?y ?loc) (alive ?x) (alive ?y) (fight ?x ?y) )
  :effect
   (and (win ?x ?y) (alive ?x) (not(alive ?y)) )
 )
 
; x kill y at loc
(:action kills-fight
  :parameters
   (?x ?y ?loc); x가 y를 loc에서 죽임
  :precondition
   (and (at ?x ?loc) (at ?y ?loc) (alive ?x) (alive ?y) (win ?x ?y) )
  :effect
   (and (kill ?x ?y) (not(alive ?y)) )
 )
 
 ; x kill z at loc
(:action judgments
  :parameters
   (?x ?y ?z ?loc); x가 y한테 진 z를 loc에서 죽임
  :precondition
   (and (at ?x ?loc) (at ?y ?loc) (at ?z ?loc) (alive ?x) (alive ?y) (alive ?z) (win ?y ?z) )
  :effect
   (and (kill ?x ?z) (not(alive ?z)) )
 )
 
 ; x kill y at loc
(:action murder
  :parameters
   (?x ?y ?loc); x가 y를 loc에서 죽임
  :precondition
   (and (at ?x ?loc) (at ?y ?loc) (alive ?x) (alive ?y) )
  :effect
   (and (kill ?x ?y) (not(alive ?y)) )
 )
)