using System.Drawing;

namespace Solsystem1
{

    public class SpaceObject
    {
        protected String name { get; set; }
        protected double orbitalRadius { get; set; }
        protected double orbitalPeriod { get; set; }
        protected double objectRadius { get; set; }
        protected double rotationPeriod { get; set; }
        protected String objectColor { get; set; }
        
       // protected Point position { get; set; }
        protected double xPosition { get; set; }
        protected double yPosition { get; set; }



        public SpaceObject(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition)
        {
            this.name = name;
            this.objectRadius = orbitalRadius;
            this.orbitalPeriod = orbitalPeriod;
            this.rotationPeriod = rotationPeriod;
            this.objectColor = objectColor;
            this.xPosition = xPosition;
            this.yPosition = yPosition;

        }

        public virtual void Draw()
        {
            Console.WriteLine(name, orbitalRadius, orbitalPeriod, rotationPeriod, objectColor, xPosition,yPosition);
        }

        public virtual void CalculatePlanetPosition(double timeInDays)
        {
        double angle = (timeInDays /orbitalPeriod) * (2 * Math.PI);
        double angleInRadiants = angle * (Math.PI / 180);
        xPosition = orbitalRadius * Math.Cos(angleInRadiants);
        yPosition = orbitalRadius * Math.Sin(angleInRadiants);


        }
    }

    public class Star : SpaceObject
    {
        public Star(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }

        public override void Draw()
        {
            Console.Write("Star : ");
            base.Draw();
        }




    }

    public class Planet : SpaceObject
    {
        public Planet(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }
        public override void Draw()
        {
            Console.Write("Planet : ");
            base.Draw();
        }
    }

    public class Moon : Planet
    {
        public Moon(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }
        public override void Draw()
        {
            Console.Write("Moon : ");
            base.Draw();
        }


    }

    public class DwarfPlanet : SpaceObject
    {
        public DwarfPlanet(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }

        public override void Draw()
        {
            Console.Write("DwarfPlanet : ");
            base.Draw();
        }
    }

    public class AsteroidBelt : SpaceObject
    {
        public AsteroidBelt(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }

        public override void Draw()
        {
            Console.Write("AstreoidBelt : ");
            base.Draw();
        }

    }

    public class Asteroid : AsteroidBelt
    {
        public Asteroid(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor, double xPosition, double yPosition) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor, xPosition, yPosition) { }
        public override void Draw()
        {
            Console.Write("Astroid : ");
            base.Draw();
        }

    }



}