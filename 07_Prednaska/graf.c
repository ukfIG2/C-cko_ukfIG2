#include "graf.h"
#include <stdio.h>

void pripravPrazdny(TGraf *g, int pocetVrcholov) {
    g->n = pocetVrcholov;
    g->m = 0;

    for (int i = 1; i <= pocetVrcholov; i++) {
        for (int j = 1; j <= pocetVrcholov; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void citaj(TGraf *g, const char *menoSuboru) {
    FILE *file = fopen(menoSuboru, "r");

    if (file == NULL) {
        printf("Subor %s sa nepodarilo otvorit.\n", menoSuboru);
        return;
    }

    int pocetVrcholov, pocetHran;
    fscanf(file, "%d %d", &pocetVrcholov, &pocetHran);

    pripravPrazdny(g, pocetVrcholov);

    for (int i = 0; i < pocetHran; i++) {
        int u, v;
        fscanf(file, "%d %d", &u, &v);
        pridajHranu(g, u, v);
    }

    fclose(file);
}

void uloz(TGraf *g, const char *menoSuboru) {
    FILE *file = fopen(menoSuboru, "w");

    if (file == NULL) {
        printf("Subor %s sa nepodarilo otvorit.\n", menoSuboru);
        return;
    }

    fprintf(file, "%d %d\n", g->n, g->m);

    for (int i = 1; i <= g->n; i++) {
        for (int j = 1; j <= g->n; j++) {
            if (g->adj[i][j]) {
                fprintf(file, "%d %d\n", i, j);
            }
        }
    }

    fclose(file);
}

void vypis(const TGraf *g) {
    for (int i = 1; i <= g->n; i++) {
        for (int j = 1; j <= g->n; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int pridajHranu(TGraf *g, int u, int v) {
    if (u < 1 || u > g->n || v < 1 || v > g->n || u == v || g->adj[u][v]) {
        return 0;
    }

    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
    g->m++;

    return 1;
}

int odoberHranu(TGraf *g, int u, int v) {
    if (u < 1 || u > g->n || v < 1 || v > g->n || u == v || !g->adj[u][v]) {
        return 0;
    }

    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
    g->m--;

    return 1;
}

int izolovaneVrcholy(const TGraf *g) {
    int pocetIzolovanych = 0;

    for (int i = 1; i <= g->n; i++) {
        int stupen = 0;

        for (int j = 1; j <= g->n; j++) {
            stupen += g->adj[i][j];
        }

        if (stupen == 0) {
            pocetIzolovanych++;
        }
    }

    return pocetIzolovanych;
}

int maxStupenVrchola(const TGraf *g) {
    int maxStupen = 0;

    for (int i = 1; i <= g->n; i++) {
        int stupen = 0;

        for (int j = 1; j <= g->n; j++) {
            stupen += g->adj[i][j];
        }

        if (stupen > maxStupen) {
            maxStupen = stupen;
        }
    }

    return maxStupen;
}

int minStupenVrchola(const TGraf *g) {
    int minStupen = g->n;

    for (int i = 1; i <= g->n; i++) {
        int stupen = 0;

        for (int j = 1; j <= g->n; j++) {
            stupen += g->adj[i][j];
        }

        if (stupen < minStupen) {
            minStupen = stupen;
        }
    }

    return minStupen;
}

int jePravidelny(const TGraf *g) {
    int stupen = -1; // Neinicializovana hodnota stupna

    for (int i = 1; i <= g->n; i++) {
        int aktStupen = 0;

        for (int j = 1; j <= g->n; j++) {
            aktStupen += g->adj[i][j];
        }

        if (stupen == -1) {
            stupen = aktStupen;
        } else if (aktStupen != stupen) {
            return 0; // Graf nie je pravidelny
        }
    }

    return 1; // Graf je pravidelny
}

int jeKompletny(const TGraf *g) {
    for (int i = 1; i <= g->n; i++) {
        for (int j = 1; j <= g->n; j++) {
            if (i != j && !g->adj[i][j]) {
                return 0; // Graf nie je kompletny
            }
        }
    }

    return 1; // Graf je kompletny
}

int jeEulerovsky(const TGraf *g) {
    for (int i = 1; i <= g->n; i++) {
        int stupen = 0;

        for (int j = 1; j <= g->n; j++) {
            stupen += g->adj[i][j];
        }

        if (stupen % 2 != 0) {
            return 0; // Graf nie je eulerovsky
        }
    }

    return 1; // Graf je eulerovsky
}

void prehladaj(const TGraf *g, int start) {
    // Implementujte prehladavanie grafu (DFS, BFS, atd.)
}

int jeSuvisly(const TGraf *g) {
    // Implementujte kontrolu, ci je graf suvisly
    return 0;
}

int komponentySuvislosti(const TGraf *g) {
    // Implementujte zistenie poctu komponent suvislosti v grafe
    return 0;
}
