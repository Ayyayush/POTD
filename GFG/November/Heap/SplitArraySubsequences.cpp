/**
 * Split Array Subsequences 
 * 
 * 
 * 
 * eg :: 2,2,3,3,4,5
 * 
 * 2,3    2,3    4,5
 * array mein elt 1 bada hona chaiye pichle index elt se 
 *
 * ! 1> we will extend the existing subsequences
 * ! 2> Otherwise we start new subsequence 
 * ! 3> At any point if a ss ends too early len<k then return false;
 * 
 * 
 * Hum ek order maintain karenge aur uske liye minheap ka use karenge 
 * minheap mein aayega {last num in subsequence, length of subsequence }
 * 
 * 
 */