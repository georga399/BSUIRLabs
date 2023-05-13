using CoupeNameSpace;
using TractorNameSpace;

Coupe porcshe = new Coupe();
porcshe.StartEngine();
porcshe.Move();
porcshe.OffEngine();

Tractor minsk = new Tractor("MTF", "minsk");
minsk.CheckEngine();
minsk.StartEngine();
minsk.Move();
minsk.OffEngine();
