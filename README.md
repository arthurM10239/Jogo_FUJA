# Jogo_FUJA
Feito Por Arthur( 01 / 05 / 2025)

Jogo feito em Raylib. Teste de dificuldades para npc

Para compilar é preciso ir no vscode, clicar 'CTRL + SHIFT + P' e acessar "Preferences:Open Keyboard Shortcuts (JSON)",
e depois coloque esse codigo que esta abaixo dentro da aba de "keybindings.json".

```c
[    
{
  "key": "ctrl+shift+b", //Aqui voce escolhera um atalho para executar seu codigo
  "command": "workbench.action.tasks.runTask",
  "args": "build-and-run",
  "when": "editorTextFocus"
}
]
