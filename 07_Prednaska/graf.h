#ifndef GRAF_H
#define GRAF_H

#define MAXV 100

typedef struct {
    int adj[MAXV + 1][MAXV + 1];
    int n;
    int m;
} TGraf;

void pripravPrazdny(TGraf *g, int pocetVrcholov);
void citaj(TGraf *g, const char *menoSuboru);
void uloz(TGraf *g, const char *menoSuboru);
void vypis(const TGraf *g);

int pridajHranu(TGraf *g, int u, int v);
int odoberHranu(TGraf *g, int u, int v);
int izolovaneVrcholy(const TGraf *g);
int maxStupenVrchola(const TGraf *g);
int minStupenVrchola(const TGraf *g);
int jePravidelny(const TGraf *g);
int jeKompletny(const TGraf *g);
int jeEulerovsky(const TGraf *g);

void prehladaj(const TGraf *g, int start);
int jeSuvisly(const TGraf *g);
int komponentySuvislosti(const TGraf *g);

#endif
