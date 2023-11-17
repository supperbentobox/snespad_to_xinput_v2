# SNES Controller to XInput Converter for Arduino Leonardo(Pro Micro)

## 概要
- これはスーパーファミコン(SFC/SNES)用のゲームパッドをArduino Leonardo互換のPro Microマイコンボードを使用してXInputデバイスとしてUSB接続するコンバーターのスケッチです
- https://github.com/ka-zuu/snes_gamepad_arduino をベースにArduino XInput Libraryを使用する形に改変したものです

## 注意
- Arduino XInput Libraryを使用するにはXInput USB Core for Arduino AVRが必要になります
  - 詳細はArduino XInput Libraryのドキュメントを参照
- 書き込み対象ボードとして「Arduino Leonardo w/XInput」を選択する必要があります
- 一度デバイスに書き込んだ後、再度書き込みを行う場合はリセットを行う必要があります
  - リセットボタンの無いPro Micro互換ボードの場合、コンパイル後書き込みが開始されたタイミング（Uploading…が表示されたタイミング）で2回、GNDとRSTをショートさせることでリセット出来ます

## 参考にしたもの
- https://zenn.dev/kazuu/articles/560c403d5be17a
- snes_gamepad_arduino
  - https://github.com/ka-zuu/snes_gamepad_arduino
- ArduinoXInput
  - https://github.com/dmadison/ArduinoXInput

## 謝辞
本ソースコードはkazuu氏による記事 https://zenn.dev/kazuu/articles/560c403d5be17a をベースにArduino XInput Libraryを使用するように改修したものです。
記事を執筆及びスケッチを作成されたkazuu氏及びArduino XInput Libraryの作者Dave Madison氏に感謝いたします。
