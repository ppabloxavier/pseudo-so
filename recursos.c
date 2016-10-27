/* Estrutura dos Recursos Disponíveis
O pseudo-SO deve, além de escalonar o processo no compartilhamento da CPU, e gerenciar o
espaço de memória de acordo com as áreas reservadas, ele deve gerenciar os seguintes recursos:
• 1 scanner
• 2 impressoras
• 1 modem
• 2 dispositivos SATA
Todos os processos, com exceção daqueles de tempo-real podem obter qualquer um desses
recursos. O pseudo-SO deve garantir que cada recurso seja alocado para um proceso por vez. Portanto, não
há preempção na alocação dos dispositivos de E/S.
Processos de tempo-real não precisam de recursos de I/O e podem ter tamanho fixo, ficando a cargo
do programador. */