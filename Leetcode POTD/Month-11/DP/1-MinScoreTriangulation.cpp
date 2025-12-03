/**
 * Minimum Score Triangluation
 * 
 * Har polygon ka value clockwise direction mein ek vector mein de diya h 
 * polygon triangluation mein usko divide krna h triangle ke form mein 
 * hamesha n sides h toh n-2 triangles bante h 
 * 
 * We have to triangluate the polygon in clockwise direction
 * har vertices ke liye hume weight mila h
 * 
 * value = [1,2,3]
 * output =6 
 * kyunki ek hi triangle banega 
 * 
 * value = [3,7,4,5]
 * output = 144 = minsum 
 * 
 * 
 * 
 * 
 * ! Thought Process
 * 
 * values= {a,b,c,d,e,f}
 * jab ek triangle bnana hota h toh 2 side ek vertices se mil jata h 
 * ek side ke liye n-1 vertices mein se ek point dekho 
 * 
 * jab ek triangle ban gya toh baaki ka bacha hissa bhi ek polygon h 
 * a*b*g  
 * toh hum dekhte h ki bade problem ke baad hum chota problem solve karenge 
 * iske liye recursion ke concept dhyaan aata h hume 
 * 
 * jab bhi line bnayenge toh polygon 2 ya 3 part mein bant jayega 
 * toh jop sub polygon h unko subproblem samjho
 * so this was the proof
 * 
 *  toh maan lo a,b,c,d,e,f mein 
 * i=0 h 
 * k= i+1 se start hoga ; k<j; k++;  
 * yha tak jayega 
 * 
 * wt= solve() + 
 *    (value[i] * value)
 * 
 * 
 * 
 * 
 */