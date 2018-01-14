let explode s =
    let rec exp i l = if i < 0 then l else exp (i - 1) (s.[i] :: l) in
    exp (String.length s - 1) [];;

let matches s = let chars = explode s in fun c -> List.mem c chars;;

let isSpace = matches " \t\n\r"
and isPunctuation = matches "()[]{}"
and isSymbolic = matches "~'!@#$%*-+=|\\:;<>.?/"
and isNumeric = matches "0123456789"
and isAlphanumeric = matches "abcdefghijklmnopqrstuvwxyz_'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";;

let rec lexwhile prop inp =
  match inp with
  c::cs when prop c -> let tok,rest = lexwhile prop cs in (Char.escaped(c)^tok,rest)
  | _ -> "",inp;;

let rec lex inp =
  match snd (lexwhile isSpace inp) with
  [] -> []
  | c::cs -> let prop = if isAlphanumeric(c) then isAlphanumeric
                        else if isSymbolic(c) then isSymbolic
                        else fun c -> false in
             let toktl,rest = lexwhile prop cs in
             (Char.escaped(c)^toktl)::(lex rest);;
