typedef struct
{
  int coeff_array[MAX_DEGREE+1];
  unsigned int high_power;
}* POLYNOMIAL;

void zero_polynomial(POLYNOMIAL poly)
{
  unsigned int i;
  for(i=0;i<=MAX_DEGREE;i++)
    poly->coeff_array[i]=0;
  poly->high_power=0;
}

void add_polynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL poly_sum)
{
  int i;
  zero_polynomial(poly_sum);
  poly_sum->high_power=max(poly1->high_power,poly2->high_power);
  for(i=poly_sum->high_power;i>=0;i--)
    poly_sum->coeff_array[i]=poly1->coeff_array[i]+poly2->coeff_array[i];
}

void mult_polynomial(POLYNOMIAL poly1,POLYNOMIAL poly2,POLYNOMIAL poly_pod)
{
  unsigned int i,j;
  zero_polynomial(poly_pord);
  poly_pord->high_power=poly1->high_power+poly2->high_power;
  if(poly_pord->high_power>MAX_DEGREE)
    error("Exceeded array size");
  else
    for(i=0;i<poly1->high_powe;i++)
      for(j=0;i<=poly2->high_power;j++)
	poly_pord->coeff_array[i+j]+=poly1-coeff_array[i]*poly2->coeff_array[j];
}

