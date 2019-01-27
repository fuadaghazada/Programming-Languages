#|
    Function that generates a set from the list given

    @param list - the list that needs to be 'setify'
|#
(define (setify list)
    (cond ((null? list) list)
          ((isElementOf (car list) (cdr list)) (setify (cdr list)))
          (else (cons (car list) (setify (cdr list))))

))

#|
    Function that checks whether the given element is
    a member of the given list

    @param element - element that needs to be checked
    @param list - the list that needs to be checked
|#
(define (isElementOf element list)
     (cond ((null? list) #f)
           ((eqv? element (car list)) #t)
           (else (isElementOf element (cdr list)))
))
