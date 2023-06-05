using Solsystem1;
using System.Collections.Generic;

class Astronomy
{
    public static void Main()
    {

        Star sun = new Star("Sun", 0, 0, 696340, 25.38, "Yellow", 0, 0);
        Planet mercury = new Planet("Mercury", 57910000, 87.97, 2439.7, 58.65, "Gray", 0, 0);
        Planet venus = new Planet("Venus", 108200000, 224.7, 6051.8, 243, "Yellow", 0, 0);
        Planet terra = new Planet("Terra", 149600000, 365.26, 6371, 0.99, "Blue", 0, 0);
        Moon theMoon = new Moon("The Moon", 384400, 27.32, 1737.5, 27.32, "Gray", 0, 0);
        AsteroidBelt theAstreoidBelt = new AsteroidBelt("The Asteroid Belt", 373000000, 0, 0, 0, "Gray", 0, 0);
        Asteroid cerses = new Asteroid("Ceres", 414000000, 1680.53, 590, 0, "Brown", 0, 0);
        DwarfPlanet pluto = new DwarfPlanet("Pluto", 5906380000, 90560, 1188.3, 6.39, "Brown", 0, 0);


        List<SpaceObject> solarSystem = new List<SpaceObject>
        {
            sun,
            mercury,
            venus,
            terra,
            theMoon,
            theAstreoidBelt,
            cerses,
            pluto
        };




        Console.WriteLine("Enter the time in days: ");
        double timeInDays = Convert.ToDouble(Console.ReadLine());

        Console.WriteLine("Enter the name of a planet: ");
        String planet = Console.ReadLine();

        switch (planet)
        {
            case "Mercury":
                mercury.CalculatePlanetPosition(timeInDays);
                mercury.Draw();
                break;



        }








        foreach (SpaceObject spaceObject in solarSystem)
        {
            spaceObject.Draw();
        }

        Console.ReadLine();
    }
}
