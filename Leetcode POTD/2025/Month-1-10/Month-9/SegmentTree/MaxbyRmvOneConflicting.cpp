/**
 * 
 * N diya hoga 
 * usssi size ka array hoga 
 * eg :: n=4    1,2,3,4
 * ek 2D array diya hoga conflictiing pair naam ka 
 * usme jo elements h wo sath nhi aa skte 
 * eg c.p == [[2,3],[1,4]]
 * so subarray 1,2,3   and 1,2,3,4   ye nhi le skte 
 * kyunki inn dono mein 2,3 sath mein h 
 * 1,4 sath mein h aisa koi subarray hi nhi h toh koi problem nhi 
 * hume maximum possible subarray count dekhna h
 * agar hum kisi bhi c.f array ko hta de 
 * maan lo 2,3 hta diya toh sab 2,3 wale subarray le skte h 
 * 
 * total hoga 9 yhi max bhi ghoga so ans == 9 
 * 
 * 
 * 
 * eg::2
 * n=5
 * {1,2,3,4,5}
 * conpair={{2,5}}
 * abhi maan lo total subarrays honge (n*n+1)/2
 * hum maan lo 2,5 ko hta dete h 
 * ab dekhte h kitne subarrays ban rhe h 
 * pair conpair ke baaki saare arrays isme consider honge 
 * 1,2,3,4,5
 * 2,3,4,5
 * 3,4,5
 * 4,5
 * 5
 * 
 * koi aisa subarrya nhi lenge jisme 3 aur 5 dono aaye 
 * so ans mein 3,4,5  4,5   5     yhi consider honge 
 * toh yha toh hume array apne maan se lena h sorting order mein 
 * toh conpair ka jo array h uske first element se > hi lenge 
 * eg 2,5 h 
 * toh sirf aise subarray lenge jinka startong elt 2 se > ho 
 * sideh maan lo 3,5 h 
 * toh 3 ke saare left wale bhi banned h 
 * kyunki wo chote h usse aur 5 tak jaane mein wo 3 ko lenge hi 
 * total subarrays nikalne ke liye 5 ko jinse jinse dikkat h wo sab nikaal lo 
 * max of 2,3 == 3 
 * 5-3 ==2 
 * toh sirf 2 subarrays ban payenge
 * 
 * 
 * aagr hum koi ek pair remove kare ab toh kaun sa krna shi hoga?
 * agar bada wala conflicitng le 
 * toh wo htaye toh gap jyada banega toh usko htane se jyada faayda h 
 * 
 * 
 * 
 * 
 */