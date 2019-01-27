#|
    Function insert-bst is defined and implemented in order to
    insert an element into a Binary Search tree

    @param item - item needed to be inserted
    @param tree - tree to which the item will be inserted
|#

(define (insert-bst item tree)

    (cond ((null? tree) (list item '() '()))
          ((< item (root tree)) (list (root tree) (insert-bst item (leftSub tree)) (rightSub tree)))
          (else (list (root tree) (leftSub tree) (insert-bst item (rightSub tree))))
))

#|
    Function that returns the root of the tree

    @param tree - tree, whose root will be returned
|#
(define (root tree)
    (car tree)
)

#|
    Function that returns the right subtree of the tree

    @param tree - tree, whose right subtree will be returned
|#
(define (rightSub tree)
    (car (cdr (cdr tree)))
)

#|
    Function that returns the left subtree of the tree

    @param tree - tree, whose left subtree will be returned
|#
(define (leftSub tree)
    (car (cdr tree))
)
