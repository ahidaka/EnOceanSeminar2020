EnOceanSeminar2020
# デモ＆勝手ハンズオン 内容

- EnOceanフィルター簡単プログラム
- Microsoft Azure IoT Plug and Play (Preview)

----
## EnOceanフィルター簡単プログラム

### 参照リポジトリ

https://github.com/ahidaka/EnOceanWindowsSamples

### 目的と概要

Visual Studioでコンパイルする簡単なC#プログラムを動作させて、EnOceanゲートウェイ開発に必要な次の基本的な機能を学習します。

- ESP3パケットの処理
- データテレグラムとTeachInテレグラム
- テレグラムフィルター

### 必要機材

- GitHub にアクセス出来る Windows PC

- Visual Studio

- USB400J または同等品

- 何らかのEnOcean センサーまたはスイッチ
(EEP A5-02-05 の温度センサーを推奨。)


### 実習準備と手順

前述の [EnOceanWindowsSamples](https://github.com/ahidaka/EnOceanWindowsSamples) リポジトリから Windows 環境にダウンロードして、中にある「[SimpleSample](https://github.com/ahidaka/EnOceanWindowsSamples/tree/master/SimpleSample)」プロジェクトを利用できるようにしておきます。

Visual Studioで **EnOceanSample.sln** を開き、ビルドしておきます。

#### プログラム起動

デバッグ実行を選択、または「▶」マーク、または「**F5**」キーを押して、プログラムをデバッグ実行すると、次の画面が開きます。右上から簡単に使い方を説明します。

- **Start** / **Stop**

    プログラムを開始または、一時停止します。

- **COM3**

    使用するCOMポートを確認または、設定します。自動認識して設定しますが、間違っている場合は変更できます。

- **Use Filter**

    プログラム開始時に指定したIDに対して、テレグラムフィルターを実行する場合にチェックします。

- [ID: 0401291D...]

    受信テレグラム表示ウィンドウです。データフィールド４バイトとともにテレグラムを表示します。

- **Temp ID**

    温度センサーの **ID** を設定します。その下の **SW ID** にはロッカースイッチの **ID** を設定します。

#### ID調査

まず **Start** ボタンをクリックしてプログラムを開始します。測定対象の温度センサーの **EnOcean ID** は次の手順でを調査します。

- テレグラム表示ウィンドウには、受信した全 EnOcean デバイスからのテレグラム・データが表示されます。

- 測定対象の温度センサーの **LEARN** ボタンを押して、**Teach-In** テレグラムを送出します。

- EnOceanSample 画面の右下に紺色白文字でプログラムが認識した Teach-In テレグラムの **EEP** と **ベンダーID** が表示されます。

- 同時にテレグラム表示ウィンドウに、通信データ４バイト目の **bit8** が立っている（この場合は **80**）データが表示されます。この **ID** が登録対象の温度センサーの **ID** です。

![ID調査](image/Sample-1P.png)
画面１　EnOceanSample ID調査

#### ID登録

前項で調査した **EnOcean ID** を、テレグラム表示ウィンドウからコピー＆ペーストして **Temp ID** に登録後、
**Start** ボタンを2回クリック（1回目：Stop, 2回目：Start）して、プログラムを再スタートします。この **EnOceanSample** プログラムは、このこのEEP A5-02-05 専用でデータ解析と変換表示する様に作られているため、これにより該当IDの温度データだけが正しく表示される様になります。（下図参照）

![ID登録](image/Sample-2.png)
画面２　EnOceanSample ID登録

#### Filter 登録

前項のID登録では、UART から入って来る全てのEnOcean受信データに対して、登録したIDとの比較を常時行って、該当データを選択して処理を行っていました。しかしこの方法ではEnOcean デバイス 15台程度以上が常時送信する環境では、シリアルポート（コントローラー）のバッファーがオーバーフローして必要なデータを取りこぼす場合があります。

対象IDをフィルター登録することで、この問題を回避することが可能です。フィルター登録機能は、すでに **EnOceanSample** プログラムに入っているため、「**Use Filter**」にチェック後、**Start** ボタンを2回クリックして、プログラムを再スタートすることで有効にできます。

下記画面の様に4行目以降に、指定ID以外のデータが表示されないことを確認してください。1～3行目には以前の記録されたIDが表示されますが、プログラムのバグなので無視して下さい。

![フィルター登録](image/Sample-3.png)
画面１　EnOceanSample フィルター登録

#### プログラムの動きを追う

さらに時間に余裕がある方は、プログラムの動きを追ってみます。

Visual Stuidio で **MainWindow.xaml.cs** のソースコードを開いて、**338行目** にブレークポイントを設定します。ここは、シリアルポートから受信した **EnOcean ID** とデータ内容の解析を行っている部分です。ステップ実行することで、C# プログラムがテレグラムから温度データを解析する様子を追うことができます。

以上で、EnOceanフィルター簡単プログラムのデモと演習は終了です。重要なことは、このまま **USB400J** や同等品を継続して使用すると **EnOcean ID によるテレグラムフィルターが有効になったままで、登録外のデバイスからのデータを受信するｋとが出来ないため、必ず抜き差し等をして設定をリセットすることをお勧めします。

![](image/VS.png)
画面１　EnOceanSample フィルター登録

----
## Microsoft Azure IoT Plug and Play (Preview)

#### 参照リポジトリ

https://github.com/ahidaka/EnOcean_IoTPnP

### 内容

シミュレーションプログラム

EnOcean ゲートウェイ＋ブローカープログラム

### 目的


