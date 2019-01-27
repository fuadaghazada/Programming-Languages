#|
    Function that joins two lists in an ordered way

    @param list1 - first list
    @param list2 - second list
|#
(define (join list1 list2)
        (cond ((null? list1) list2)
              ((null? list2) list1)
              ((> (car list1) (car list2)) (cons (car list2) (join (cdr list2) list1)))
              ((< (car list1) (car list2)) (cons (car list1) (join (cdr list1) list2)))
              (else (cons (car list2) (join (cdr list2) (cdr list1))))
              ))
