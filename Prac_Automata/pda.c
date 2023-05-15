// To construct a PDA (Pushdown Automaton) for the language L = {a^n b^4n c^m | m, n >= 1}, 

// δ is defined as follows:

// δ(q0, ε, Z) = {(q1, AZ)}
// δ(q1, a, A) = {(q1, AA)}
// δ(q1, ε, Z) = {(q2, Z)}
// δ(q2, b, A) = {(q2, ε)}
// δ(q2, ε, Z) = {(q3, Z)}
// δ(q3, b, A) = {(q3, ε)}
// δ(q3, b, Z) = {(q4, Z)}
// δ(q4, b, Z) = {(q4, Z)}
// δ(q4, c, Z) = {(q5, Z)}
// δ(q5, c, Z) = {(q5, Z)}
// δ(q5, ε, Z) = {(q6, Z)}
//Set of final/accepting states (F): F = {q6}

 //L= { WCWR | W € (0+1)* }. Construct a PDA 
/*
δ(q0, ε, Z0) = (q1, Z0)
δ(q1, 0, Z0) = (q1, 0Z0)
δ(q1, 1, Z0) = (q1, 1Z0)
δ(q1, ε, Z0) = (q2, Z0)
δ(q2, 0, 0) = (q2, ε)
δ(q2, 1, 1) = (q2, ε)
δ(q2, ε, Z0) = (q3, Z0)
δ(q3, 0, 0) = (q3, ε)
δ(q3, 1, 1) = (q3, ε)
δ(q3, ε, Z0) = (q4, Z0)

// Set of final/accepting states (F):
F = {q4}
*/


//L= { a^n b^4n | n>=1 }. Construct a PDA

/*
δ(q0, a, Z0) = (q1, AZ0)
δ(q1, a, A) = (q1, AA)
δ(q1, b, A) = (q2, ε)
δ(q2, b, A) = (q2, ε)
δ(q2, ε, Z0) = (q3, Z0)
δ(q3, b, Z0) = (q4, Z0)
δ(q4, b, Z0) = (q4, Z0)
δ(q4, ε, Z0) = (q5, Z0)

Set of final/accepting states (F):
F = {q5}

*/

