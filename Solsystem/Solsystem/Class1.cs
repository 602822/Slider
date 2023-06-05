using System.Diagnostics;

namespace Solsystem
{

    public class SpaceObject
    {
        protected String name {  get; set; }
        protected double orbitalRadius { get; set; }
        protected double orbitalPeriod { get; set; }
        protected double objectRadius { get; set; }
        protected double rotationPeriod { get; set; }
        protected String objectColor { get; set; }



        public SpaceObject(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor)
        {
            this.name = name;
            this.objectRadius = orbitalRadius;
            this.orbitalPeriod = orbitalPeriod;
            this.rotationPeriod = rotationPeriod;
            this.objectColor = objectColor;
          
        }

        public virtual void Draw()
        {
            Console.WriteLine(name, orbitalRadius, orbitalPeriod,rotationPeriod,objectColor);
        }
    }

    public class Star : SpaceObject
    {
        public Star(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base( name,  orbitalRadius, orbitalPeriod,  objectRadius,  rotationPeriod,objectColor) {}

        public override void Draw()
        {
            Console.Write("Star : ");
            base.Draw();
        }
    }

        public class Planet : SpaceObject
        {
            public Planet(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor) { }
        public override void Draw()
            {
                Console.Write("Planet : ");
                base.Draw();
            }
        }

        public class Moon : Planet
        {
            public Moon(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor) { }
        public override void Draw()
            {
                Console.Write("Moon : ");
                base.Draw();
            }


        }

    public class DwarfPlanet : SpaceObject
    {
        public DwarfPlanet(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor) { }

        public override void Draw()
        {
            Console.Write("DwarfPlanet : ");
            base.Draw();
        }
    }
    
    public class AstroidBelt : SpaceObject
    {
        public AstroidBelt(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base(name, orbitalRadius, orbitalPeriod, objectRadius, rotationPeriod, objectColor) { }

        public override void Draw()
        {
            Console.Write("AstreoidBelt : ");
            base.Draw();
        }

    }

    public class Astroid : AstroidBelt
    {
     public Astroid(String name, double orbitalRadius, double orbitalPeriod, double objectRadius, double rotationPeriod, String objectColor) : base( name,  orbitalRadius, orbitalPeriod,  objectRadius,  rotationPeriod,objectColor) {}

        public override void Draw()
        {
            Console.Write("Astroid : ");
            base.Draw();    
        }

    }



}
