type expression =
    Var of string
    | Const of int
    | Add of expression * expression
    | Mul of expression * expression;;

let simplify1 expr =
    match expr with
    Add(Const(m), Const(n)) -> Const(m + n)
    | Mul(Const(m), Const(n)) -> Const(m * n)
    | Add(Const(0), x) -> x
    | Add(x, Const(0)) -> x
    | Mul(Const(0), _) -> Const(0)
    | Mul(_, Const(0)) -> Const(0)
    | Mul(Const(1), x) -> x
    | Mul(x, Const(1)) -> x
    | _ -> expr;;

let rec simplify expr =
    match expr with
    Add(e1, e2) -> simplify1(Add(simplify e1, simplify e2))
    | Mul(e1, e2) -> simplify1(Mul(simplify e1, simplify e2))
    | _ -> simplify1 expr;;
