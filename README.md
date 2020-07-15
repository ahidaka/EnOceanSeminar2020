EnOceanSeminar2020
# デモ＆勝手ハンズオン 内容

https://ahidaka.github.io/EnOceanSeminar2020/

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
(EEP A5-02-05 の温度センサーを推奨)


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
画面３　EnOceanSample フィルター登録

#### プログラムの動きを追う

さらに時間に余裕がある方は、プログラムの動きを追ってみます。

Visual Stuidio で **MainWindow.xaml.cs** のソースコードを開いて、**338行目** にブレークポイントを設定します。ここは、シリアルポートから受信した **EnOcean ID** とデータ内容の解析を行っている部分です。ステップ実行することで、C# プログラムがテレグラムから温度データを解析する様子を追うことができます。

以上で、EnOceanフィルター簡単プログラムのデモと演習は終了です。重要なことは、このまま **USB400J** や同等品を継続して使用すると **EnOcean ID によるテレグラムフィルターが有効になったままで、登録外のデバイスからのデータを受信するｋとが出来ないため、必ず抜き差し等をして設定をリセットすることをお勧めします。

![EnOceanSampleデバッグ](image/VS.png)
画面４　Visual Studio EnOceanSample のデバッグ 

<br/>

----
## Microsoft Azure IoT Plug and Play (Preview)

### 参照リポジトリ

https://github.com/ahidaka/EnOcean_IoTPnP

### 目的と概要

Microsoft Azure IoT Central / PnP (Preview) サービスと EnOcean マルチセンサーを事例にして、クラウドサービスと EnOcean システムの連携方法を理解します。

デモ＆実習では次の2種類の方法を用意しています。

1. シミュレーションプログラム

    実際のセンサーを使用せず、EnOcean のセンサーとゲートウェイをシミュレーションするプログラムを使用して、Azure IoT Central と IoT PnP を体験します。

2. EnOcean ゲートウェイ＋ブローカープログラム

    EnOceanゲートウェイプログラムとEnOcean センサー、 IoT PnP 対応のブローカープログラムを使用して、実際のセンサー情報をAzure IoT Central と IoT PnP で参照します。

### 必要機材

（実習に必須なもの、シミュレーター利用の場合）
- GitHub にアクセス出来る Linux PC(Ubuntu 18.04推奨), WSL, またはRaspberry Pi

- Node.js + npm 実行環境

- Microsoft Azure IoT Centralにアクセスするブラウザ環境

- Microsoft Azure IoT Centralアカウント（必須）

（以下はオプション、実機利用の場合）

- USB400J または同等品

- 何らかのEnOcean センサーまたはスイッチ
(EEP A5-02-05 の温度センサーを推奨)

<br/>

### 実習準備と手順（ 1. と 2. 共通）

#### Azure IoT Central アプリケーションの作成

[「Azure IoT Central アプリケーションの作成」](https://docs.microsoft.com/ja-jp/azure/iot-central/core/quick-deploy-iot-central) 手順に従って、「カスタム アプリ」 > 「カスタム アプリケーション」 テンプレートを使用して、中身が空のカスタム アプリケーションを作成します。

次の様な Azure IoT Central アプリケーション ダッシュボードが使えれば、OK です。

![IoT Central アプリケーション](image/iotc.png)
画面５　Microsoft Azure IoT Central アプリケーション ダッシュボード 

#### dps-keygen のインストール

- dps-keygen のインストール
    
    下記コマンドを実行して **dps-keygen** を利用可能にしてください。Node.js と npm を事前にインストールしておく必要があります。

    ```sh
    sudo npm i -g dps-keygen
    ```
 
- ■ アドバイス<br/>
    dps-keygen コマンドは実行して結果の文字列が得られれば良いため、必ずしも前記シミュレータープログラムと同じ環境にインストールする必要はありません。既存の Linux環境への Node.js と npm のインストールは、インストール済の他のモジュールとのバージョン整合が取れないために、苦労する場合があります。

- リポジトリの入手とインストール
    
    前述の [EnOcean_IoTPnP](https://github.com/ahidaka/EnOcean_IoTPnP) リポジトリ全体を Linux 環境にダウンロードしておきます。

    **7月14日以前に入手した方は、上記公開プログラムバイナリーをこのセミナー用に更新しているため、ダウンロードし直して下さい。**

#### デバイスキーの作成

[デバイス キーの生成](https://docs.microsoft.com/ja-jp/azure/iot-central/core/tutorial-connect-pnp-device#generate-device-key) 手順に従って、
前項で作成した「カスタム アプリケーション」の「管理」タブの「デバイス接続」ページで、
**このアプリの SAS トークン** の「キーの表示」をクリックして
「主キー」をコピーして保存します。

同じ **デバイス接続** 画面の **ID スコープ** は、後でアプリケーション起動時に使用するため、一時的にコピーして保存しておきます。

次に示すように dps-keygen コマンドを実行して生成・表示された デバイス キー をメモしておきます。
表示されたこの値は、後でアプリケーション起動時に使用します。

##### デバイス キーの生成 コマンド
```sh
dps-keygen -di:enocean-001 -mk:{上記で入手した「主キー」}
```

di:パラメータで指定するデバイスID は、任意に設定可能です。今回の事例では、enocean-001 としています。このキー生成に使用したデバイス名も、後でアプリケーション起動時に使用するため、保存しておきます。

<br/>

### シミュレーター版の実行

手順が簡単のため、実デバイスを持っている場合でも、先にシミュレーター プログラムで動作確認しておくことをお勧めします。

#### シミュレーターのインストール

以下の様に実行環境のアーキテクチャに応じたバイナリープログラムを、ダウンロードした **EnOcean_IoTPnP** リポジトリから、/usr/local/bin または Home ディレクトリ等の適当なディレクトリにコピーして下さい。コピーするだけでインストールは完了です。

- Raspberry pi シリーズ<br/>
 
    [simulatepnp/bin/armv7l/simulatepnp](simulatepnp/bin/armv7l/simulatepnp)

- Ubuntu 18.04 x86_64 PC または WSL<br/>

    [simulatepnp/bin/x86_64/simulatepnp](simulatepnp/bin/x86_64/simulatepnp)

#### シミュレーターの実行

実行は、次の通りコピーしたバイナリープログラムを Linux shell から起動するだけです。ビルドは必要ありません。実行後、画面にはたくさんのログメッセージが表示されます。

```sh
./simulatepnp [デバイス ID] [ID スコープ] [デバイス キー]
```

#### 例

```sh
./simulatepnp enocean-001 0ne0010FFFF 1rmxGaeTzBsCarlTaxyzOL9XXXXXXXXXXXXXXXXwOUg=
```

４．動作検証

前項１．で作成したアプリケーションのデバイス画面を開きます。前項でのプログラムの実行後、Plug and Play 動作でテンプレートとデバイスが自動作成されるには、30秒程度の時間がかかるため、少し待ちます。やがて、下記画面例の様に「デバイス」>「すべてデバイス」に「EnOcean PnP Test-2」のテンプレート名が現れ、その下に前項のシミュレーター プログラム起動時に指定した「デバイス ID」（この例では enocean-001 ）が表示されます。

[![iotc-device-p65.png](image/iotc-device-p65.png "デバイスが画面")](image/iotc-device.png)

##### 画面：すべてデバイスでの デバイス ID 表示

この画面で作成した「デバイスID」（この例では enocean-001 ）をクリックして「デバイス情報画面」を表示させます。さらに30秒程度待つと、自動的に生成されたグラムやデバイス情報画面での描画が始まります。

ソースコード（[simulatepnp/EnOceanPnPTest2_1yu_impl.c](simulatepnp/EnOceanPnPTest2_1yu_impl.c)）を見ると分かる通り、テレメトリーの値はシミュレーター プログラム用に、乱数で生成しています。テレメトリーの送信間隔は 2秒 に設定しています。

[![iotc-sim1-p50.png](image/iotc-sim1-p50.png "シミュレーター動作画面")](image/iotc-sim1.png)

##### 画面：シミュレーター動作画面例

５．動作終了

起動した Linux Shell 画面で、「Control-C」 を入力してシミュレーター プログラムを終了します。

////////

- 機材の準備
    STM550J と USB400J（または同等品）を用意してください。USB400J は動作環境マシンに装着します。
    Windows PC を使用して、EnOcean Dolphin View Advance ツールを使用して同様確認をしておきます。

- ■アドバイス：<br/>
    EnOcean Dolphin View Advance アプリケーションは、EnOcean GmbH の [開発ツールダウンロードページ](https://www.enocean.com/en/support/download/) から入手します。

    最新版は以下の3.8.6.0 です。入手にはメールアドレスによるアカウント登録が必要です。
    https://www.enocean.com/en/support/download/dolphinview-advanced/DolphinViewAdvanced3_8_6_0.exe/

    EnOcean ゲートウェイ プログラム は以下の別リポジトリにあります。
    
    [EnOceanGateways リポジトリ](https://github.com/ahidaka/EnOceanGateways)


２．デバイスキーの作成

デバイスキーの生成手順は、前項の手順と同じです。また、前項で作成した デバイス ID やデバイスキー を流用することも可能ですし、今回例えば デバイス ID を **enocean-002** 等として、新たに作成して使用することも可能です。

３．センサー登録

動作環境にインストールした EnOcean ゲートウェイ プログラム(dpride)を、次のオプションで「センサー登録モード」起動して、マルチセンサーを動作環境に登録します。

```sh
sudo ./dpride -c -r
```

- ■アドバイス：<br/>
    USB等のデバイスIOポートにアクセスするため、管理者権限で実行します。<br/>
    初出時、"sudo" が抜けいました。申し訳ございません。

その後マルチセンサーの **LEARNボタン** を押して、デバイス登録を完了します。
起動画面にデバイス登録済のメッセージが出力されます。

![マルチセンサーの LEARNボタン](image/learn-p25mark.jpg)

- ■アドバイス：<br/>
    LEARNボタンは奥まった場所にあるので、クリップの先などで押します。

登録完了後は、「Control-C」で ゲートウェイ プログラムを一旦終了します。

４．実行

先にEnOcean ゲートウェイ プログラム (dpride) をオペレーション モードで起動します。
```sh
./dpride -o
```
次に別の Shell画面を開いて、Plug and Play 実行プログラムを起動します。
各プログラムをバックグラウンドで実行することも可能ですが、それぞれ起動画面に動作状況ログを出力するのと、ともに「Control-C」で停止させることから、別画面で起動した方が使い勝手が良いです。
```sh
./enoceanpnp [デバイス ID] [ID スコープ] [デバイス キー]
```

#### 例

```sh
./enoceanpnp enocean-002 0ne0010FFFF 1rmxGaeTzBsCarlTaxyzOL9XXXXXXXXXXXXXXXXwOUg=
```

５．動作検証

動作検証も基本的には、前項のシミュレーターの場合と同じです。起動時に指定した デバイスID を指定して、IoT Central のデバイス情報表示画面で確認可能です。加速度センサーや開閉センサーは、ほぼ即時にセンサーデータを送信するため、ほぼリアルタイムでの動作確認ができます。

６．動作終了

dpride enoceanpnp ともに「Control-C」 を入力してシミュレーター プログラムを終了します。

以上

