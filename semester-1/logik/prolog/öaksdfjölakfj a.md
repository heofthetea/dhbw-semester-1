 [[Liste]]
 [[Rekursive Prädikate]]
## löaid flkaj fölkj
Write a 3-place predicate combine_list which takes three lists as arguments and combines the elements of the first two lists into the third as follows:
### Expected Outcome
```Prolog
   ?-  combine_list([a,b,c],[1,2,3],X).  
   X = [a,1,b,2,c,3]  
   ?-  combine_list([f,b,yip,yup],[glu,gla,gli,glo],Result).  
   Result = [f,glu,b,gla,yip,gli,yup,glo]
```

[[combine.pl]]

## aölsdkfjöalfk
Now write a 3-place predicate combine_tuple which takes three lists as arguments and combines the elements of the first two lists into the third as follows:

```Prolog
   ?-  combine_tuple([a,b,c],[1,2,3],X).  
     
   X  =  [[a,1],[b,2],[c,3]]  
     
   ?-  combine_tuple([f,b,yip,yup],[glu,gla,gli,glo],Result).  
     
   Result  =  [[f,glu],[b,gla],[yip,gli],[yup,glo]]
```

[[combine_as_tuple.pl]]

