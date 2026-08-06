const statusElement=document.getElementById("status");
function showStatus(message,isError=false){statusElement.textContent=message;statusElement.style.color=isError?"#fca5a5":"#86efac";}
async function setLed(state){try{showStatus("Sending command...");const response=await fetch(`control.php?state=${state}`,{cache:"no-store"});const data=await response.json();if(!response.ok||!data.success)throw new Error(data.message||"Server error");showStatus(state===1?"LED is ON":"LED is OFF");}catch(error){showStatus(`Error: ${error.message}`,true);}}
async function loadStatus(){try{const response=await fetch("control.php",{cache:"no-store"});const data=await response.json();if(!response.ok||!data.success)throw new Error(data.message||"Could not read status");showStatus(data.state==="1"?"LED is ON":"LED is OFF");}catch(error){showStatus(`Error: ${error.message}`,true);}}
loadStatus();
