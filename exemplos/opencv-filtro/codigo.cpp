#include <opencv2/opencv.hpp>
#include <iostream>

// Função principal
int main(int argc, char** argv) {
    // 1. Definir o arquivo de imagem de entrada
    // Você pode passar o caminho da imagem como argumento na linha de comando
    // ou alterar a string abaixo diretamente.
    std::string image_path = (argc > 1) ? argv[1] : "imagem.jpeg";

    // 2. Carregar a imagem
    // cv::IMREAD_GRAYSCALE: Carrega a imagem diretamente em tons de cinza (1 canal).
    // O algoritmo Canny funciona internamente com imagens monocromáticas.
    cv::Mat src = cv::imread(image_path, cv::IMREAD_GRAYSCALE);

    // Verificar se a imagem foi carregada corretamente
    if (src.empty()) {
        std::cerr << "Erro: Nao foi possivel carregar a imagem: " << image_path << std::endl;
        return -1;
    }

    // Criar uma janela para exibir a imagem original
    cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
    cv::imshow("Original", src);

    // --- Aplicação do Filtro Canny ---

    // Imagem de destino que conterá o resultado (mapa de bordas binário)
    cv::Mat edges;

    // Parâmetros do Detector de Bordas Canny
    // threshold1: Limite inferior para a histerese (usado para conectar bordas)
    // threshold2: Limite superior para a histerese (usado para detectar as bordas fortes iniciais)
    double limiar_inferior = 50;
    double limiar_superior = 150;
    
    // Regra prática: threshold2 geralmente é 2x ou 3x maior que threshold1.

    // 3. Chamar a função cv::Canny
    cv::Canny(src, edges, limiar_inferior, limiar_superior);

    // Opcional: Aplicar um leve desfoque Gaussiano ANTES do Canny pode ajudar a reduzir
    // bordas falsas causadas por ruído, caso a imagem original seja muito ruidosa.
    // Exemplo:
    // cv::Mat img_suave;
    // cv::GaussianBlur(src, img_suave, cv::Size(3, 3), 0);
    // cv::Canny(img_suave, edges, limiar_inferior, limiar_superior);

    // 4. Exibir o resultado
    cv::namedWindow("Detector de Bordas Canny", cv::WINDOW_AUTOSIZE);
    cv::imshow("Detector de Bordas Canny", edges);

    // 5. Salvar a imagem resultante (opcional)
    cv::imwrite("saida_canny.png", edges);
    std::cout << "Imagem de bordas salva como 'saida_canny.png'" << std::endl;

    // Aguardar tecla para fechar
    std::cout << "Pressione qualquer tecla na janela de imagem para sair..." << std::endl;
    cv::waitKey(0);

    return 0;
}