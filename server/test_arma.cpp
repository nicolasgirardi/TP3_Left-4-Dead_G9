#include <CppUTest/CommandLineTestRunner.h>

#include "./include/armas/arma.h"
#include "./include/armas/idf.h"
#include "./include/armas/p90.h"
#include "./include/armas/scout.h"
#include "./include/armas/creador_armas.h"

TEST_GROUP(arma_test) {
    IDF* idf;
    P90* p90;
    Scout* scout;

    void setup() {
        idf = new IDF();
        p90 = new P90();
        scout = new Scout();
    }

    void teardown() {
        delete idf;
        delete p90;
        delete scout;
    }
};

TEST(arma_test, iniciar_disparo) {
    idf->iniciar_disparo();
    std::string estado = idf->get_estado();
    CHECK_EQUAL(estado, "3 10 1 1");
}

TEST(arma_test, finalizar_disparo) {
    idf->iniciar_disparo();
    idf->finalizar_disparo();
    std::string estado = idf->get_estado();
    CHECK_EQUAL(estado, "3 10 1 0");
}

TEST(arma_test, disparar) {
    idf->iniciar_disparo();
    idf->disparar();
    std::string estado = idf->get_estado();
    CHECK_EQUAL(estado, "3 9 1 1");
}

TEST(arma_test, recargar) {
    idf->iniciar_disparo();
    idf->disparar();
    idf->recargar();
    std::string estado = idf->get_estado();
    CHECK_EQUAL(estado, "3 10 1 1");
}

TEST(arma_test, get_tipo_arma) {
    int tipo_arma = idf->get_tipo_arma();
    CHECK_EQUAL(tipo_arma, 3);
}