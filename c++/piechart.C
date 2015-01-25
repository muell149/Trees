void piechart()
{
  // Pie chart example.
  //Authors: Olivier Couet, Guido Volpi
   
  Float_t vals[] = {0.2150,0.0632,0.0264,0.6954};
    //Float_t vals[] = {1,1,1,1};
  //  Float_t vals[] = {0.0264,0.0632,0.215,0.6954};
  Int_t colors[] = {2,3,6,4};
  Int_t nvals = 4;//sizeof(vals)/sizeof(vals[0]);

  TCanvas *cpie = new TCanvas("cpie","TPie test",900,700);
  //  cpie->Divide(2,2);

  TPie *pie1 = new TPie("pie1",
			"Pie with offset and no colors",nvals,vals);
  TPie *pie2 = new TPie("pie2",
			"Pie with radial labels",nvals,vals,colors);
  TPie *pie3 = new TPie("pie3",
			"Higgs Branching Fractions @ m_{H} = 125 GeV",nvals,vals,colors);
  TPie *pie4 = new TPie("pie4",
			"Pie with verbose labels",nvals,vals,colors);

  // cpie->cd(1);
  // pie1->SetAngularOffset(30.);
  // pie1->SetEntryRadiusOffset( 4, 0.1);
  // pie1->SetRadius(.35);
  // pie1->Draw("3d");

  // cpie->cd(2);
  // pie2->SetEntryRadiusOffset(2,.05);
  // pie2->SetEntryLineColor(2,2);
  // pie2->SetEntryLineWidth(2,5);
  // pie2->SetEntryLineStyle(2,2);
  // pie2->SetEntryLabel(0,"balls");
  // pie2->SetEntryFillStyle(1,3030);
  // pie2->SetCircle(.5,.45,.3);
  // pie2->Draw("rsc");

  // cpie->cd(3);
  //pie3->SetY(.32);
  //pie3->SetAngularOffset(30.);
  pie3->SetRadius(0.3);
  //  pie3->SetHeight(0.06);
  //pie3->GetSlice(0)->SetValue(.8);
  pie3->SetEntryRadiusOffset( 3, 0.1);

  pie3->SetEntryLabel(0,"WW");
  pie3->SetEntryLabel(2,"ZZ");
  pie3->SetEntryLabel(1,"#tau#tau");
  pie3->SetEntryLabel(3,"other");
  pie3->SetLabelsOffset(0.03);
  pie3->SetLabelFormat("%txt %perc");
  pie3->Draw("3d");
  //TLegend *pieleg = pie3->MakeLegend();
  //pieleg->SetY1(.56); pieleg->SetY2(.86);

  // cpie->cd(4);
  // pie4->SetRadius(.2);
  // pie4->SetLabelsOffset(.01);
  // pie4->SetLabelFormat("#splitline{%val (%perc)}{%txt}");
  // pie4->Draw("nol <");
}
