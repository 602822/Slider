
using Solsystem;

class Astronomy
{

  public static void Main()
  {

        List<SpaceObject> solarSystem = new List<SpaceObject>
         {
            new Star("Sun"),
            new Planet("Mercury"),
            new Planet("Venus"),
            new Planet("Terra"),
            new Moon("The Moon"),
            new AstroidBelt("The Astreoid belt"),
            new Astroid("Ceres"),
            new DwarfPlanet("Pluto")

         };


        foreach(SpaceObject spaceObject in solarSystem)
        {
            spaceObject.Draw(); 
        }
        Console.ReadLine();

   }




}



