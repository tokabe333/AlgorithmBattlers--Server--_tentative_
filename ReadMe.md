# オンラインでアルゴリズムとかAIとか戦わせたいやーつ

## 各環境について
### サーバ
ゲームシステムをPythonで動かすと速度的にもったいない気がした<br>
速度とJSON関連考えてC#使いたい
- Nginx
- Django
- MySQL
- Docker
- .NET Core 3.1

### フロントエンド
要件満たしてきれいに作れるならなんでもいいや<br>
せっかくだし**Angular**使ってもいい気がする

## 環境構築
### Python3.7
- Linuxのコマンドからファイト
- pipとか使えるようにして

### C# (.NET Core 3.1)
**windows** → https://dotnet.microsoft.com/download <br>
**Linux**   → 備忘録を参照

- #### VS Code 拡張機能
	- C#
	- C# Extensions
	- C# FixFormat
	- C# XML Documentation Comments
	- Preferences → Setting → editor.codeLens=false

- #### .net core コマンド
	**※各種コマンドはプロジェクトディレクトリに移動して実行**
	- **バージョン確認** → dotnet new 
	- **プロジェクト作成** → dotnet new [テンプレート名] --name [プロジェクト名] --ouput [出力ディレクトリ]
	- **コンパイル&実行** → dotnet run
	- **コンパイルのみ** → dotnet build
	- **コンパイル(リリース)** → dotnet build -c release
<br><br>

## 備忘録
### 環境構築関連
- Ubuntu 18.04 に .NET Core SDK 3.1 をインストールする
https://qiita.com/tabizou/items/f47983d1d327e6c5d5e1

### .net関連
- コマンドラインでC#プログラミング
https://qiita.com/shuhey/items/b4211f196259156df8f4
- dotnet コマンド要約
https://qiita.com/akatuki77/items/36bdb9d071a44e45ffe6

### マークダウン関連
- マークダウン記法 一覧表・チートシート
https://qiita.com/kamorits/items/6f342da395ad57468ae3
- Markdown (strict)の自分なりのまとめ
http://myjquery.blog.fc2.com/blog-entry-34.html


