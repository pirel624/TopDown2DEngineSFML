#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include <vector>



// Whats wrong


    // mouse direction calculation, is false

// Working on:
    // Bullet refresh






/*class fsm
{
private:



};*/

namespace constant
{
    const float pi = 3.141592;
}



namespace debug
{
    class log
    {
    private:
        static const int ukuran = 10;
        int position = 0;
        std::string masalah[ukuran];
    public:

        void add(std::string apa)
        {
            if(position < ukuran)
            {
                masalah[position] = apa;
                position++;
            }else if(position >= ukuran){}else{}
        }
        void pop()
        {
            position--;
            masalah[position] = "";
        }
        void display()
        {
            for(int n = 0; n < position + 1; n++)
            {
                std::cout << masalah[position] << std::endl;
            }
        }
    };

    static log daftar_masalah;



    class screen_log
    {
    public:
        std::string prompt_1;
        std::string prompt_2;
        std::string prompt_3;
        std::string prompt_4;
        std::string prompt_5;

        float val_1;
        float val_2;
        float val_3;
        float val_4;
        float val_5;

        void display()
        {
            system("cls");
            std::cout << prompt_1 << " : " << val_1 << std::endl;
            std::cout << prompt_2 << " : " << val_2 << std::endl;
            std::cout << prompt_3 << " : " << val_3 << std::endl;
            std::cout << prompt_4 << " : " << val_4 << std::endl;
            std::cout << prompt_5 << " : " << val_5 << std::endl;
        }
    };


}


namespace alg
{


    float com_max(float a, float b, float c, float d)
    {

        float angka[4] = {a, b, c, d};
        float banyak = 4;

        float besar = a;



            for(int n = 0; n < banyak; n++)
            {
                if(besar < angka[n])
                {
                    besar = angka[n];
                }else{}



            }

        return besar;
    }

    float com_min(float a, float b, float c, float d)
    {

        float angka[4] = {a, b, c, d};
        float banyak = 4;

        float kecil = a;



            for(int n = 0; n < banyak; n++)
            {
                if(kecil > angka[n])
                {
                    kecil = angka[n];
                }else{}



            }

        return kecil;
    }




    bool isinmiddle(float awal, float b, float akhir)
    {

        float minimal = std::fmin(awal, akhir);
        float maksimal = std::fmax(awal, akhir);

        if((minimal <= b) && (b <= maksimal)){return true;}else{return false;}


    }





}


namespace math
{
    bool isequal(float a, float b, double tolerance = 0.001)
    {

        float different = std::fabs(a - b);

        if(different <= tolerance){return true;}
        else{return false;}
    }



}


namespace basic
{
    struct point{float x = 0; float y = 0; bool invalid = false;};
    struct square
    {
        private:
            point vertices[4];
            point anchor;
            float sizex;
            float sizey;

        public:

            square(float x = 1, float y = 1, float six = 1, float siy = 1)
            {
                anchor.x = x;
                anchor.y = y;
                sizex = six;
                sizey = siy;

                vertices[0] = {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
                vertices[1] = {(anchor.x + sizex / 2), (anchor.y - sizey / 2)};
                vertices[2] = {(anchor.x + sizex / 2), (anchor.y + sizey / 2)};
                vertices[3] = {(anchor.x - sizex / 2), (anchor.y + sizey / 2)};

            }

            void square_one(float x, float y, float six, float siy)
            {
                anchor.x = x;
                anchor.y = y;
                sizex = six;
                sizey = siy;

                vertices[0] = {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
                vertices[1] = {(anchor.x + sizex / 2), (anchor.y - sizey / 2)};
                vertices[2] = {(anchor.x + sizex / 2), (anchor.y + sizey / 2)};
                vertices[3] = {(anchor.x - sizex / 2), (anchor.y + sizey / 2)};

            }

            void update()
            {
                vertices[0] = {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
                vertices[1] = {(anchor.x + sizex / 2), (anchor.y - sizey / 2)};
                vertices[2] = {(anchor.x + sizex / 2), (anchor.y + sizey / 2)};        // Calculating vertices position based on anchor point and size. Use it after geometrical transformation
                vertices[3] = {(anchor.x - sizex / 2), (anchor.y + sizey / 2)};

            }

            sf::Vector2f posisisfml()
            {
                    return {(anchor.x - sizex / 2), (anchor.y - sizey / 2)};
            }

            sf::Vector2f ukuransfml()
            {
                return {sizex, sizey};
            }

            point& pusat = anchor;
            float& ukuranx = sizex;
            float& ukurany = sizey;


            point& sudut1 = vertices[0];
            point& sudut2 = vertices[1];
            point& sudut3 = vertices[2];
            point& sudut4 = vertices[3];

    };




    struct segment{

        point a; point b;  // Lets just say that a is 1 and b is 2

        float slope;
        float constant;
        bool isParalleltoX = false;
        bool isParalleltoY = false;
        bool isUpdated = false;

        segment(float x1 = 0, float y1 = 0, float x2 = 0, float y2 = 0)   // Konstrukto (Fungis inisisasi)
        {
            a.x = x1;a.y = y1; b.x = x2; b.y = y2; // Assigning the segment ends point coordinates

            if(y2 == y1 && x2 != x1){isParalleltoX = true;}    // Ruas sejajar dengan sumbu x
            else if(y2 != y1 && x2 == x1){isParalleltoY = true;}// Ruas sejajar dengan sumbu y
            else                                              // Ruas bioasa biasa aja
            {
                slope = (y2 - y1) / (x2 - x1);
                constant = y1 - slope * x1;
            }

            isUpdated = true;   // Mengatakan ke komputer bahwa ruas garis ini telah di update
        }

        void update()
        {
            float& x1 = a.x;
            float& y1 = a.y;   // Adaptor untuk baris kode yang di kopi paste dari bagian di atas, saya ,ales nulis lagi :)
            float& x2 = b.x;
            float& y2 = b.y;

            if(y2 == y1 && x2 != x1){isParalleltoX = true;}    // Ruas sejajat dengan sumbu x
            else if(y2 != y1 && x2 == x1){isParalleltoY = true;} // Ruas sejajar dengan sumbu y
            else                                              // Ruas biasa biasa aja
            {
                slope = (y2 - y1) / (x2 - x1);
                constant = y1 - slope * x1;
            }

            isUpdated = true; // Mengatakan ke program bahwa ruas ini telah  di upodate

        }

        void change_a(float r, float s)
        {
            a.x = r;
            a.y = s;
            isUpdated = false;   // Karena posisi diganti, belum di update

        }
        void change_b(float r, float s)
        {
            b.x = r;
            b.y = s;
            isUpdated = false; // Karena posisi di ganti, belum di update
        }
        bool isNew(){return isUpdated;}




    };

    struct circle
    {
        private:

            float radius;
            float diameter;
            point anchor;

        public:

            circle(float x, float y, float r)
            {
                anchor.x = x; anchor.y = y; radius = r; diameter = radius * 2;
            }

            float& rad = radius;
            float& dia = diameter;
            float& x = anchor.x;
            float& y = anchor.y;

    };
};

namespace collision
{

    using namespace basic;

    bool aabb(square kot1, square kot2)
    {
        /*
            point& sudut1 = vertices[0];
            point& sudut2 = vertices[1];
            point& sudut3 = vertices[2];
            point& sudut4 = vertices[3];

            point& pusat = anchor;
            float& ukuranx = sizex;
            float& ukurany = sizey;

        */

        float& a1 = kot1.sudut1.x;
        float& a2 = kot1.sudut2.x;
        float& b1 = kot1.sudut1.y;
        float& b4 = kot1.sudut4.y;

        float& c1 = kot2.sudut1.x;
        float& c2 = kot2.sudut2.x;
        float& d1 = kot2.sudut1.y;
        float& d4 = kot2.sudut4.y;



        if(( alg::com_max(std::fabs(b1 - d4), std::fabs(b1 - d1), std::fabs(b4 - d1), std::fabs(b4 - d4)) <= (std::fabs(b4 - b1) + std::fabs(d4 -d1))) && (alg::com_max(std::fabs(a1 - c2), std::fabs(a1 - c1), std::fabs(a2 - c2), std::fabs(a2 - c1)) <= (std::fabs(a2 - a1) + std::fabs(c2 - c1))) )

            {return true;}

                else{return false;}



    }


    point intersect(basic::segment gar1, basic::segment gar2)
    {
        point intersection;
        if(!gar1.isNew()){gar1.update();}   // Memperbarui keadaan garis, perlu untuk pemrosesan berikutnya
        if(!gar2.isNew()){gar2.update();}

        if(!gar1.isParalleltoX && !gar1.isParalleltoY && !gar2.isParalleltoX && !gar2.isParalleltoY)   // Jika garis normal
        {
            if(gar1.slope != gar2.slope){
            intersection.x = (gar2.constant - gar1.constant) / (gar1.slope - gar2.slope);
            intersection.y = gar1.slope * intersection.x + gar1.constant;}

            else{
                intersection.invalid = true;
            }
            return intersection;

            debug::daftar_masalah.add("Garis Normal");
        }else
        {
            if((gar1.isParalleltoX || gar2.isParalleltoX) && (!gar1.isParalleltoX || !gar2.isParalleltoY) && (!gar2.isParalleltoX || !gar1.isParalleltoY))    // Jika salah satu garis sejajar dengan sumbu x
            {
                segment xpar;
                segment normal;


                float b;
                float a;
                if(gar1.isParalleltoX){xpar = gar1; normal = gar2;}
                else if(gar2.isParalleltoX){xpar = gar2; normal = gar1;}

                b = xpar.a.y;
                a = (b - normal.constant) / normal.slope;std::cout << "here" << std::endl;

                intersection.x = a;
                intersection.y = b;

                return intersection;
                debug::daftar_masalah.add("Salah satu garis sejajar dengan sumbu x");

             }else if((gar1.isParalleltoY || gar2.isParalleltoY) && !(gar1.isParalleltoX || gar2.isParalleltoY) && !(gar2.isParalleltoX || gar1.isParalleltoY))  // JIka salah satu garis sejajar dengan sumbyu y
             {
                segment ypar;
                segment normal;


                float b;
                float a;
                if(gar1.isParalleltoY){ypar = gar1; normal = gar2;}
                else if(gar2.isParalleltoY){ypar = gar2; normal = gar1;}

                a = ypar.a.x;
                b = normal.slope * a + normal.constant;

                intersection.x = a;
                intersection.y = b;

                return intersection;
             }else if((gar1.isParalleltoX && gar2.isParalleltoY) || (gar1.isParalleltoY && gar2.isParalleltoX))  // Jika salah satu paralel dengan sumbu x dan yang satunt paralel dengan sumbu y
             {
                 segment ypar;
                 segment xpar;

                 if(gar1.isParalleltoX){xpar = gar1; ypar = gar2;}      // Menentukan garis mana yang sejajar dengan sumbu x dan yang mana yang sejajar dengabh sumbu y
                 else if(gar1.isParalleltoY){xpar = gar2; ypar = gar1;}

                 intersection.x = ypar.a.x;
                 intersection.y = xpar.a.y;



                 return intersection;
             }else if(gar1.isParalleltoX && gar2.isParalleltoX)    //JIka kedua garis sejajar dengn sumbu x
             {
                 if(gar1.a.y == gar2.a.y) // JIka kedua garis berada pada posoisi y yang sama, berarti dapt diketahui lokasi tabrakannya
                 {
                     float x;
                     float y = gar2.a.y;
                     float minx = alg::com_min(gar1.a.x, gar1.b.x, gar2.a.x, gar2.b.x);
                     float maxx = alg::com_max(gar1.a.x, gar1.b.x, gar2.a.x, gar2.b.x);
                     x = minx + (maxx - minx) / 2;
                     intersection.x = x;
                     intersection.y = y;
                     return intersection;

                 }else // Jika kedau garis berada pada popsisi y yang berbeda, berarti tak dapat diketahui temp[at tabtraknnya, karena tidak mungkin tabrakan
                 {
                     intersection.invalid = true;
                     return intersection;
                 }
             }
             else if(gar1.isParalleltoY && gar2.isParalleltoY)  // Kedua garis sejajar dengan sumbu y
             {
                 if(gar1.a.x == gar2.a.x) // JIka kedua garis berada pada posoisi x yang sama, berarti dapt diketahui lokasi tabrakannya
                 {
                     float x = gar2.a.x;
                     float y;
                     float miny = alg::com_min(gar1.a.y, gar1.b.y, gar2.a.y, gar2.b.y);
                     float maxy = alg::com_max(gar1.a.y, gar1.b.y, gar2.a.y, gar2.b.y);
                     y = miny + (maxy - miny) / 2;
                     intersection.x = x;
                     intersection.y = y;
                     return intersection;

                 }else // Jika kedau garis berada pada popsisi x yang berbeda, berarti tak dapat diketahui temp[at tabtraknnya, karena tidak mungkin tabrakan
                 {
                     intersection.invalid = true;
                     return intersection;
                 }
             }else
             {
                 debug::daftar_masalah.add("Anjayyyyyyy Bangsat !!!");
                 intersection.invalid = true;
                 return intersection;
             }


        }

    }

    bool isinsegment(point titik, segment gar)
    {
        if(!titik.invalid){
        if(!gar.isParalleltoX && !gar.isParalleltoY)
        {

            if(math::isequal(titik.y, titik.x * gar.slope + gar.constant) && alg::isinmiddle(gar.a.x, titik.x, gar.b.x) && alg::isinmiddle(gar.a.y, titik.y, gar.b.y)){return true;}
            else{return false;}

        }else if(gar.isParalleltoX)
        {
            if(titik.y == gar.a.y && alg::isinmiddle(gar.a.x, titik.x, gar.b.x)){return true;}
            else{return false;}

        }else if(gar.isParalleltoY)
        {
            if(titik.x == gar.a.x && alg::isinmiddle(gar.a.y, titik.y, gar.b.y)){return true;}
            else{return false;}
        }

        else{return false;}
    }else if(titik.invalid){return false;}
    else{return false;}
    }



    bool segment_collision(basic::segment gar1, basic::segment gar2)
    {
        point tabrak = intersect(gar1, gar2);

        if(isinsegment(tabrak, gar1) && isinsegment(tabrak, gar2)){return true;}
        else{return false;}
    }
};









class strict_int
{
private:
    int mini;
    int maxi;
    int val;

public:
    strict_int(int x = 0, int y = 100, int z = 100)
    {
        // Threshold check
        if(z > y){z = y;}
        if(z < x){z = x;}

        //Threshold assignment
        mini = x;
        maxi = y;
        val = z;
    }

    bool change(int nilai, bool forced=true)
    {
        bool balik = false;

        if(((nilai + val) <= maxi) && ((nilai + val) >= mini))           // Main algorithm
        {
            val = val + nilai;
            balik = true;
        }else
        {
            if(forced)
            {
                if(val + nilai < mini){val = mini;balik = true; }          // if forced
                else if(val + nilai > maxi){val = maxi;balik = true; }
            }else{}
        }

        return balik;
    }

    int get_value(){return val;}

    void extend(int minimal = 0, int maksimal = 0)
    {
        mini = minimal;
        maxi = maksimal;
    }
};


class player
{
private:
    std::string name;
    strict_int health;
    int pos_x;        // Based on screen coordiante system, not cartesian
    int pos_y;
    bool isDead;
    basic::square bentuk;   // Creating hitbox

public:
    player()
    {
        pos_x = 0;
        pos_y = 0;
        name = "blank";
        isDead = false;
        bentuk.square_one(pos_x, pos_y, 20, 20);
    }

    void inflict_damage(int x)
    {
        health.change(-x);
        if(health.get_value() <= 0){isDead = true;}

    }

    void traverse(int distance = 0, std::string direction = "null")
    {
        if     (direction == "up"){pos_y -= distance;}
        else if(direction == "down"){pos_y += distance;}
        else if(direction == "left"){pos_x -= distance;}
        else if(direction == "right"){pos_x += distance;}
        else{}

        bentuk.pusat.x = pos_x;
        bentuk.pusat.y = pos_y;        // Geometrical transformation of hitbox based on player position

        bentuk.update();           // Updating vertices position
    }

    basic::square hitbox()
    {
        return bentuk;
    }

};


class projectile
{
private:
    basic::square bentuk;
    int momentum;
    int damage;
    int direction;       // direction, clockwise, degree
    bool isAlive;
    // Debug
        float trig_degree;
        float rad;
        float d_y;
        float d_x;

public:
    projectile(int arah = 45)
    {
        bentuk.square_one(300,300, 20, 20);
        momentum = 100;
        damage = 10;
        direction = arah;
        isAlive = false;



    }

    void pass_second(int waktu)
    {
        if(isAlive){
            float delta_x = 0;                                     // for measuring change in position based in trigonometrical calculation
            float delta_y = 0;

            float hypotenuse = waktu * momentum / 10;                  // Calculating hypotenuse for trigonometrical calculation, representing bullet kinetical energy

            int trigonometrical_degree;                            // Used for measuring triangle alignment for conventional trigobometrical calculation

            if(direction >= 0 && direction <= 90)
            {
                trigonometrical_degree = 90 - direction;           // Measuring triangle allignmet based on bullet main direction  (note: angle used to represent bullet direction is not the same as the angle to calculate trigonometrical stuff, which use conventional counter_clockwise orientation)
            }else if(direction > 90 && direction <= 360)
            {
                trigonometrical_degree = 450 - direction;
            }else{}

            trig_degree = trigonometrical_degree;                  // !!Just for debug!! Measuring trigonomtrical angle

            float radian = trigonometrical_degree * constant::pi / 180; // Turning degree into radian
            rad = radian;                                          // !!Just for debug!! Measuring radian, for debuuging log purposes
            delta_y =  -(sin(radian)* hypotenuse);                  // Measuring the change of bullet position on y axis
            delta_x =  cos(radian) * hypotenuse;                  // Measuring the change of bullet position on x axis
            d_y = delta_y * 1000;
            d_x = delta_x * 1000;

            bentuk.pusat.x += delta_x;                             // translate the change onto bullet anchor
            bentuk.pusat.y += delta_y;
            bentuk.update();                                       // Updating bullet's vertices

            momentum -= 1 * waktu;                                 // Reduction of momentum, because it is used, duhh
        }
        if(momentum <= 0)
        {
            isAlive = false;                                   // Checking bullet active condition based on its current momentum
        }

    }

    basic::square mesh()
    {
        return bentuk;
    }

    void refresh(int x = 300, int y = 300)

    {
        isAlive = true;
        momentum = 100;
        bentuk.pusat.x = x;
        bentuk.pusat.y = y;
    }
    float trig_deg()
    {
        return trig_degree;
    }
    float r()
    {
        return rad;
    }
    float y()
    {
        return bentuk.pusat.y;
    }
    float x()
    {
        return bentuk.pusat.x;
    }

    void change_direction(int cyka)
    {
        direction = cyka;
    }
    bool alive()
    {
        return isAlive;
    }

    int moment()
    {
        return momentum;
    }





};







class line_particle
{
private:
    bool isActive;      // Flag used to check whether the particle is dead or not
    strict_int lifespan_asmilisecond; // Particle lifespan
    int max_lifespan;  // Particle max lifespan
    sf::VertexArray garis;     // Vertices, used for vector rendering

public:
    line_particle(int value_for_max_lifespan = 200)
    {
        max_lifespan = value_for_max_lifespan;         // Setting max lifespan
        lifespan_asmilisecond.extend(0, max_lifespan);   // setup for lifespan's strict_int's threshold
        lifespan_asmilisecond.change(max_lifespan);         // assigjning lifespan
        isActive = true;       // activating particle


        garis.setPrimitiveType(sf::Lines);       // Setting particle as a line segment
        garis.resize(2);                         // setting amoungt of vertices                    // Vector graphics
        garis[0].position = {20, 20};            // setting vertex position
        garis[1].position = {40, 40};            // setting vertex position

    }

    void change_position(int x1, int y1, int x2, int y2)
    {
        garis[0].position = {x1, y1};            // setting vertex position
        garis[1].position = {x2, y2};            // setting vertex position

    }

    void pass_through_time(sf::Time waktu)
    {
        lifespan_asmilisecond.change(-(waktu.asMilliseconds()));   // Age the particle
        if(lifespan_asmilisecond.get_value() <= 0)        // Checking whether the particle is dead or not
        {
            isActive = false;
        }
    }

    void refresh()
    {
        isActive = true;                                         // set as alive
        lifespan_asmilisecond.change(max_lifespan);            // determining lifespan
    }

    sf::VertexArray drawable()
    {
        return garis;                            // return sf::Drawable to be rendered in rendering phase
    }

    bool isAlive()
    {
        return isActive;
    }

    int get_lifespan_asmilisecond()
    {
        return lifespan_asmilisecond.get_value();
    }
    void kill()
    {
        isActive = false;
    }





};



class line_particle_manager
{
private:
    std::vector<line_particle> garis[10];

public:
    line_particle_manager()
    {
        int banyak = sizeof(garis) / sizeof(line_particle);
        for(int x = 0; x , banyak; x++)
        {

        }
    }










};




   // Projectile main shape center position not updated !!!!!!





int main()
{

    // Initial setup

    static debug::screen_log anjay;

    int x = 200;                                                                           // Setting up main anchor
    int y = 200;
    static const int screen_x = 800;
    static const int screen_y = 800;


    sf::RenderWindow main_window(sf::VideoMode(screen_x, screen_y), "Prototype by Muhammad Pirel");  // Setting up renderer

    sf::Event event;                                                                       // Instancing event container
    //sf::Clock waktu;                                                                     // Creating timer


    sf::RectangleShape kotak;
    kotak.setFillColor(sf::Color::Blue);                                                   // Creating an object to be rendered
    kotak.setSize({20, 20});
    kotak.setPosition({x, y});


    bool starting = true;
    sf::Texture intro;
    intro.loadFromFile("INTRO.png");                                                        // Preparation for intro window
    sf::Sprite logo;
    logo.setTexture(intro);
    logo.setPosition({200, 200});


    line_particle garis[100];                                                              // Initializing main line particle


    sf::Mouse tikus;                                                                        // Preparing mouse input query container
    static sf::Vector2i MOUSE_LOCATION  ;


    projectile peluru [100];                                                                 // Initialization / preparation for bullets and its sprites
    sf::RectangleShape peluru_gpu[100];
    for(int x = 0; x <10 ; x++)
    {
        peluru_gpu[x].setFillColor(sf::Color::Blue);
        peluru_gpu[x].setSize(peluru[x].mesh().ukuransfml());
        peluru_gpu[x].setPosition(peluru[x].mesh().posisisfml());

    }

    static bool KEY_W;
    static bool KEY_A;
    static bool KEY_S;                                                                      // Preparing input flag
    static bool KEY_D;
    static bool MB_1;
    static bool MB_2;




    while(main_window.isOpen())
    {
        // check whetehr the window is closed or not
        while(main_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){main_window.close();} // finish execution if closed
        }

        // Initialisation

        if(starting)
        {
            main_window.clear();
            main_window.draw(logo);
            main_window.display();
            sf::sleep(sf::seconds(3));
            starting = false;
        }




        // Main game loop

            // Input ======================================================================================


            KEY_W = false;
            KEY_A = false;
            KEY_S = false;                                                    // Refresh input flag
            KEY_D = false;
            MB_1 = false;
            MB_2 = false;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){KEY_W = true;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){KEY_S = true;}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){KEY_A = true;}    // Keyboard input
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){KEY_D = true;}

            if(tikus.isButtonPressed(sf::Mouse::Left)){MB_1 = true;}
            if(tikus.isButtonPressed(sf::Mouse::Right)){MB_2 = true;}         // mouse button input
            MOUSE_LOCATION = tikus.getPosition(main_window);                  // Mouse location query






            // Simulation ====================================================================================

            if(KEY_W){y -= 7;}
            if(KEY_A){x -= 7;}                                              // Moving central anchor based on Keyboard input (WASD)
            if(KEY_S){y += 7;}
            if(KEY_D){x += 7;}


            kotak.setPosition({x, y});                                      // sync player with central anchor position



            if(MB_1)
            {
                float arah = std::atan((-MOUSE_LOCATION.y + y) / (MOUSE_LOCATION.x - x) );            // SALAH !!!!!
                float direction;

                if(arah <= 90 && arah >= 0)
                {
                    direction = 90 - arah;
                }else if(arah <= 360 && arah > 90)                         // Preparing angle magnitude for projectile direction input
                {
                    direction = 450 - arah;
                }else{}

                for(int n = 0; n < 100; n ++)
                {
                     if(!peluru[n].alive())                                // reactivate dead bullet, and change the attribute based on mouse input
                     {
                         peluru[n].refresh(x, y);
                         peluru[n].change_direction(direction);            // Kenapa cepet mati: fps kegedan
                         break;
                     }
                }
                    //std::cout << peluru[3].alive();                        // !!Just for Debug!!  Checking whether a bullet is alive or not
                for(int n = 0; n < 100; n++)
                {
                    if(!garis[n].isAlive())
                    {
                        garis[n].change_position(x, y, MOUSE_LOCATION.x, MOUSE_LOCATION.y); // Update and refresh dead line particle, according to mouse input
                        garis[n].refresh();
                    }

                }

            }

            for(int x = 0; x < 100; x ++)
            {
                peluru[x].pass_second(1);
                                                                           // Move bullets according to passsing time ( Projectile Instance)
            }

            for(int x = 0; x <100 ; x++)
            {
                peluru_gpu[x].setFillColor(sf::Color::Blue);
                if(!peluru[x].alive()){peluru_gpu[x].setFillColor(sf::Color::Black);}
                peluru_gpu[x].setSize(peluru[x].mesh().ukuransfml());      // Updating bullet's sprite according to bullets cureent positions
                peluru_gpu[x].setPosition(peluru[x].mesh().posisisfml());

            }


            // Rendering ================================================================================================

            main_window.clear();                                                    // Flush out previous buffer
            main_window.draw(kotak);
            for(int n = 0; n < 100; n++)
            {
                if(garis[n].isAlive()){main_window.draw(garis[n].drawable());}                // Draw line particle
                garis[n].pass_through_time(sf::milliseconds(1000));
            }
                                                                // Redraw the buffer
            /*std::cout << std::endl;
            std::cout << garis.isAlive();
            std::cout << garis.get_lifespan_asmilisecond();*/
            anjay.prompt_1 = "Kehidupan peluru 3";
            anjay.val_1 = peluru[3].alive();
            anjay.prompt_2 = "Posisi x peluru 3";
            anjay.val_2 = peluru[3].x();
            anjay.prompt_3 = "posisi y peluru 3";
            anjay.val_3 = peluru[3].y();
            anjay.prompt_4 = "Main anchor x";
            anjay.val_4 = x;
            anjay.prompt_5 = "Main anchor y";
            anjay.val_5 = y;


            for(int x = 0; x < 100; x ++)
            {
                main_window.draw(peluru_gpu[x]);
            }

            main_window.display();                                                   // Render 2d image
            anjay.display();











    }

}

