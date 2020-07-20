using namespace GeFiCa;
// calculate and save fields of a square point-pontact (SPC) HPGe
void calculateFields(const char *output="SPC.root")
{
   SquarePointContact detector;
   detector.Bias[0]=-70*volt; // bias on point contact
   detector.Bias[1]=0; // ground outer contact

   detector.Height=1.0*cm;
   detector.Width=detector.Length=1.8*cm;
   detector.WrapAroundW=detector.WrapAroundL=detector.Length;

   detector.PointContactW=0.6*mm;
   detector.PointContactL=0.6*mm;
   detector.PointContactH=0.1*mm;

   detector.BottomImpurity=4e9/cm3; detector.TopImpurity=4e9/cm3;

   int nx=50; 
   int ny=50; // precision: 0.1 mm
   int nz=100; // precision: 0.1 mm
   XYZ grid(nx,ny,nz);
   grid.SetupWith(detector);
   grid.RelaxationFactor=1.94;
   grid.SuccessiveOverRelax();
   
   TFile file(output,"recreate");
   detector.Write();
   grid.Write();
   file.Close();
}
