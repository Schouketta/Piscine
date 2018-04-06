#include "grman/grman.h"
#include <iostream>
#include <map>
#include <allegro.h>
#include "graph.h"
using namespace std;
int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();


    BITMAP* page;
    BITMAP* fond;
    page=create_bitmap(SCREEN_W,SCREEN_H);

    fond = load_bitmap("aigle1.bmp", NULL);

    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    grman::menu_afficher(page,fond);




    while ( !key[KEY_ESC] )
    {


        while(mouse_b&1)
        {

            if (getpixel(screen,mouse_x,mouse_y)==makecol(225,206,154))

            {

                g.grapheNiveau2();
                g.forteConnexite();
                //g.afficherPoidsAretes();
                //g.afficherMap();

                //g.supprimerSommet();
                //g.afficherMap();
                //g.afficherPoidsAretes();
                //g.ajouterSommet();


                g.update();



            }

            if (getpixel(screen,mouse_x,mouse_y)==makecol(121,121,248))

            {

                g.grapheNiveau1();
               // g.forteConnexite();
                //g.afficherMap();
                //g.supprimerSommet();
                //g.afficherMap();
                g.afficherPoidsAretes();
                //g.ajouterSommet();


                g.update();




            }
            if (getpixel(screen,mouse_x,mouse_y)==makecol(127,206,114))

            {
                exit(1);

            }

            if (getpixel(screen,mouse_x,mouse_y)==makecol(150,225,174))

            {

                g.grapheNiveau3();
                g.afficherMap();
                //g.supprimerSommet();
                g.afficherMap();
                //g.afficherPoidsAretes();
                //g.ajouterSommet();



                g.update();



            }

            g.update();

            /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();


        }

    }



    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();




