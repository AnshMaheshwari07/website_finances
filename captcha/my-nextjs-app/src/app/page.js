import Captcha from "./components/Captcha";

export default function Home() {
  return (
   <main>
    <input type="text" placeholder="message"></input>
    <div><Captcha/></div>
    <button type="submit">send</button>
   </main>
  );
}
